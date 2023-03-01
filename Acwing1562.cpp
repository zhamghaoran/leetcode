#include "bits/stdc++.h"

using namespace std;
struct faq {
    int f, t, nex;
} rt[100010];
int head[100010];
int cnt;

void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int a, b;
int vis[1010];

void dfs(int x, int dis) {
    if (dis >= b)
        return;
    for (int i = head[x]; i; i = rt[i].nex) {
        vis[rt[i].t] = 1;
        dfs(rt[i].t, dis + 1);
    }
}

int get(int y) {
    memset(vis, 0, sizeof vis);
    dfs(y, 0);
    int ans = 0;
    vis[y] = 0;
    for (int i = 1; i <= a; i++) {
        if (vis[i])
            ans++;
    }
    return ans;
}

int main() {
    int x, y;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= x; j++) {
            scanf("%d", &y);
            add(y, i);
        }
    }
    cin >> x;
    for (int i = 1; i <= x; i++) {
        scanf("%d", &y);
        cout << get(y) << endl;
    }
    return 0;
}