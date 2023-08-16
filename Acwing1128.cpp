#include "bits/stdc++.h"

using namespace std;
struct node {
    int f, t, nex, val;
} rt[100010];

int head[100010];
int cnt;

void add(int x, int y, int z) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}


int a, b;
int ans[1000010];

int main() {
    cin >> a >> b;
    int x, y, z;
    for (int i = 1; i <= b; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    memset(ans, 0x3f, sizeof ans);
    ans[1] = 0;
    queue<int> p;
    p.push(1);
    while (!p.empty()) {
        x = p.front();
        p.pop();
        for (int i = head[x]; i; i = rt[i].nex) {
            if (ans[rt[i].t] > ans[x] + rt[i].val) {
                ans[rt[i].t] = ans[x] + rt[i].val;
                p.push(rt[i].t);
            }
        }
    }
    int maxx = 0;
    for (int i = 1; i <= a; i++) {
        maxx = max(maxx, ans[i]);
        if (ans[i] == 0x3f3f3f3f) {
            cout << -1;
            exit(0);
        }
    }
    cout << maxx;
    return 0;
}