#include "bits/stdc++.h"

#define N 200010
using namespace std;

struct node {
    int f, t, nex;
} rt[200010];
int cnt;
int head[200010];

void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int k;
bool faq = false;
int dfn[N], low[N];
int a, b;
int val[N], sta[N], cnt1, neww[N], qaq;
void dfs(int x) {
    dfn[x] = low[x] = ++cnt;
    sta[++cnt1] = x;
    for (int i = head[x]; i; i = rt[i].nex) {
        if (!dfn[rt[i].t]) {
            dfs(rt[i].t);
            low[x] = min(low[x], low[rt[i].t]);
        }
        if (!neww[rt[i].t]) {
            low[x] = min(low[x], dfn[rt[i].t]);
        }
    }
    int siz = 0;
    if (low[x] == dfn[x]) {
        qaq++;
        neww[x] = qaq;
        siz++;
        while (x != sta[cnt1]) {
            neww[sta[cnt1]] = qaq;
            cnt1--;
            siz++;
        }
        if (siz != k && siz > 1) {
            faq = true;
        }
        cnt1--;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        int n;
        cin >> n >> k;
//        memset(head, 0, sizeof head);
//        memset(low, 0, sizeof low);
//        memset(dfn, 0, sizeof dfn);
//        memset(sta, 0, sizeof dfn);
//        memset(neww, 0, sizeof dfn);
        for (int i = 0;i <= n + 10;i ++) {
             head[i] = 0;
             low[i] = 0;
             dfn[i] = 0;
             sta[i] = 0;
             neww[i] = 0;
        }
        faq = false;
        int x;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                cin >> x;
                if (x != i) {
                    faq = true;
                }
            }
        } else {

            for (int i = 1; i <= n; i++) {
                cin >> x;
                if (x == i) {
                    faq = true;
                }
                add(i, x);
            }
            cnt1 = 0;
            for (int i = 1; i <= n; i++) {
                if (!dfn[i])
                    dfs(i);
            }
        }
        if (faq) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }

    }
    return 0;
}
/*
1
2 2
1 1
 *
 */