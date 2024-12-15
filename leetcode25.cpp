#include <bits/stdc++.h>

#define N 1000010
using namespace std;
struct node {
    int f, t, nex;
} rt[N];
int head[N];
int cnt;
int val[N];
int a, b;
int dfn[N];
int low[N];
int sta[N];
int tot;
int neww[N];
int minn[N];
int ru[N];
int qaq;

void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

void dfs(int x) {
    dfn[x] = low[x] = ++cnt;
    sta[++tot] = x;
    for (int i = head[x]; i; i = rt[i].nex) {
        if (!dfn[rt[i].t]) {
            dfs(rt[i].t);
            low[x] = min(low[x], low[rt[i].t]);
        }
        if (!neww[rt[i].t]) {
            low[x] = min(low[x], dfn[rt[i].t]);
        }
    }
    if (low[x] == dfn[x]) {
        neww[x] = ++qaq;
        minn[qaq] = min(minn[qaq], val[x]);
        while (sta[tot] != x)
            minn[qaq] = min(minn[qaq], val[sta[tot]]), neww[sta[tot--]] = qaq;
        tot--;
    }
}

int main() {
    memset(val, 0x3f, sizeof val);
    memset(minn, 0x3f, sizeof minn);
    cin >> a;
    cin >> b;
    int x, y;
    for (int i = 1; i <= b; i++) {
        cin >> x >> y;
        val[x] = y;
    }
    cin >> b;
    for (int i = 1; i <= b; i++) {
        cin >> x >> y;
        add(x, y);
    }
    cnt = 0;
    for (int i = 1; i <= a; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = head[i]; j; j = rt[j].nex) {
            if (neww[rt[j].f] != neww[rt[j].t]) {
                ru[neww[rt[j].t]]++;
            }
        }
    }
    for (int i = 1; i <= qaq; i++) {
        if (ru[i] == 0) {
            if (minn[i] < 0x3f3f3f3f) {
                ans += minn[i];
            } else {
                cout << "NO" << endl;
                for (int j = 1; j <= a; j++) {
                    if (neww[j] == i) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl << ans;
    return 0;
}
