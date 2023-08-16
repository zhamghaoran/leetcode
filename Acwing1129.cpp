#include <bits/stdc++.h>

using namespace std;
struct node {
    int f, t, val, nex;
} rt[100010];
int head[100010];
int cnt;
int vis[100010];

void add(int x, int y, int z) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int ans[100010];

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, z;
    for (int i = 1; i <= b; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    memset(ans, 0x3f, sizeof ans);
    ans[c] = 0;
    priority_queue<pair<int, int>> p;
    p.push(make_pair(0, c));
    while (!p.empty()) {
        auto qaq = p.top();
        p.pop();
        if (vis[qaq.second])
            continue;
        vis[qaq.second] = 1;
        for (int i = head[qaq.second]; i; i = rt[i].nex) {
            if (ans[rt[i].t] > ans[qaq.second] + rt[i].val) {
                ans[rt[i].t] = ans[qaq.second] + rt[i].val;
                p.push(make_pair(-ans[rt[i].t], rt[i].t));
            }
        }
    }
    cout << ans[d];
    return 0;
}