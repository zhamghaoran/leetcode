#include "bits/stdc++.h"

#define INF 0x3f3f3f3f
using namespace std;
int a, b;
struct node {
    int f, t, val, nex;
} rt[100010];
int head[100010];
int cnt;
int s, t;
int cur[100010];
int vis[100010];

void add(int x, int y, int z) {
    rt[cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt++;
    rt[cnt].t = x;
    rt[cnt].f = y;
    rt[cnt].val = 0;
    rt[cnt].nex = head[y];
    head[y] = cnt++;
}

int dfs(int x, int lim) {
    if (x == t)
        return lim;
    int flow = 0;
    for (int i = cur[x]; ~i; i = rt[i].nex) {
        if (vis[rt[i].t] == vis[x] + 1 && rt[i].val) {
            int ans = dfs(rt[i].t, min(rt[i].val, lim - flow));
            if (!ans)
                vis[rt[i].t] = -1;
            rt[i].val -= ans;
            rt[i ^ 1].val += ans;
            flow += ans;
        }
    }
    return flow;
}

bool bfs() {
    queue<int> q;
    ::memset(vis, -1, sizeof vis);
    cur[s] = head[s];
    vis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int qaq = q.front();
        q.pop();
        for (int i = head[qaq]; ~i; i = rt[i].nex) {
            if (vis[rt[i].t] == -1 && rt[i].val) {
                vis[rt[i].t] = vis[qaq] + 1;
                cur[rt[i].t] = head[rt[i].t];
                if (rt[i].t == t)
                    return true;
                q.push(rt[i].t);
            }
        }
    }
    return false;
}

int dic() {
    int flow = 0;
    int ans;
    while (bfs()) {
        while ((ans = dfs(s, INF)))
            flow += ans;
    }
    return flow;
}

int main() {
    ::memset(head, -1, sizeof head);
    cin >> a >> b;
    s = 0;
    t = a * 2 + 1;
    int x, y, z;
    long long faq = 0;
    for (int i = 1; i <= b; i++) {
        cin>>x>>y>>z;
        add(x, x * 2 + y, z);
        faq += z;
    }
    for (int i = 1; i <= a; i++) {
        add(0, i, INF);
    }
    for (int i = a + 1; i <= 2 * a; i++) {
        add(i, 2 * a + 1, INF);
    }
    cout << z - dic();
    return 0;
}