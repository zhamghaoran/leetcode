#include "bits/stdc++.h"
#define MAXX 300000
using namespace std;
struct node {
    int f, t, nex;
} rt[MAXX];
int cnt;
int val[MAXX];
int a;
int du[MAXX];
int head[MAXX];

void add(int x, int y) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    du[y]++;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int ans;
int maxx;

void dfs(int x) {
    ans++;
    for (int i = head[x]; i; i = rt[i].nex) {
        dfs(rt[i].t);
    }
}

int solve() {
    maxx = 0;
    memset(head, 0, sizeof head);
    memset(du, 0, sizeof du);
    cnt = 0;
    cin >> a;
    for (int i = 1; i <= a; i++)
        scanf("%d", &val[i]);
    int x, y;
    for (int i = 1; i < a; i++) {
        scanf("%d%d", &x, &y);
        if (val[x] > val[y])
            add(x, y);
        else if (val[y] > val[x])
            add(y, x);
    }
    for (int i = 1; i <= a; i++) {
        if (!du[i]) {
            ans = 0;
            dfs(i);
            maxx = max(maxx, ans);
        }
    }
    return maxx;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}