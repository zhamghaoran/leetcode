#include "bits/stdc++.h"
#define N 200010
#define int long long
using namespace std;
struct node {
    int f, t, nex;
} rt[N];
int head[N];
int cnt;

void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int a, b;
int siz[N];
int val[N];
int son[N];
int top[N];
int fa[N];
int dep[N];
int sum[N];

void dfs1(int x, int f) {
    siz[x] = 1;
    fa[x] = f;
    dep[x] = dep[f] + 1;
    for (int i = head[x]; i; i = rt[i].nex) {
        if (rt[i].t != f) {
            val[rt[i].t] += val[x];
            dfs1(rt[i].t, x);
            siz[x] += siz[rt[i].t];
            if (siz[rt[i].t] > siz[son[x]])
                son[x] = rt[i].t;
        }
    }
}

void dfs(int x) {
    if (x == son[fa[x]])
        top[x] = top[fa[x]];
    else
        top[x] = x;
    if (son[x])
        dfs(son[x]);
    for (int i = head[x]; i; i = rt[i].nex) {
        if (rt[i].t != fa[x] && rt[i].t != son[x]) {
            dfs(rt[i].t);
        }
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    return x;
}

signed main() {
    cin >> a >> b;
    int x, y;
    for (int i = 1; i < a; i++) {
        scanf("%lld%lld", &x, &y);
        add(x, y);
        add(y, x);
        val[x]++;
        val[y]++;
    }
    dfs1(1, 0);
    dfs(1);
    for (int i = 1; i <= b; i++) {
        scanf("%lld%lld", &x, &y);
        int lca1 = lca(x, y);
        cout << val[x] + val[y] - 2 * val[lca1] + (val[lca1] - val[fa[lca1]])<<endl;
    }
    return 0;
}