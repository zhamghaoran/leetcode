#include "bits/stdc++.h"

using namespace std;
int a;
int xx[2010];
int yy[2010];
int val[2010];
int k[2010];
struct node {
    int f, t;
    long long val;
}rt[20100];
int cnt;
int fa[2010];
int head[2010];
int vis[100010];

int fin(int x) {
    if (fa[x] != x)
        return fa[x] = fin(fa[x]);
    return fa[x];
}

void add(int f, int t, int vall) {
    rt[++ cnt].f = f;
    rt[cnt].t = t;
    rt[cnt].val = vall;
    head[f] = cnt;
}

void unin(int x, int y) {
    x = fin(x);
    y = fin(y);
    fa[x] = y;
}

int main() {
    cin >> a;
    for (int i = 1; i <= a; i++) fa[i] = i;
    for (int i = 1; i <= a; i++)
        ::scanf("%d%d", &xx[i], &yy[i]);
    for (int i = 1; i <= a; i++)
        ::scanf("%d", &val[i]), add(0, i, val[i]);
    for (int i = 1; i <= a; i++)
        ::scanf("%d", &k[i]);

    for (int i = 1; i <= a; i++) {
        for (int j = i + 1; j <= a; j++) {
            add(i, j, (abs(xx[i] - xx[j]) + abs(yy[i] - yy[j])) * (k[i] + k[j]));
        }
    }

    std::sort(rt + 1, rt + 1 + cnt, [&](node a, node b) -> bool {
        return a.val < b.val;
    });

    int count = 0;
    vector<int> build;
    vector<pair<int, int>> xian;
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (fin(rt[i].f) != fin(rt[i].t)) {
            ans += rt[i].val;
            unin(rt[i].f, rt[i].t);
            xian.emplace_back(rt[i].f, rt[i].t);
            count++;
            vis[i] = 1;
        }
    }
    int count1 = 0;
    for (int i = 1;i <= cnt;i ++) {
        if (vis[i]) {
            if (!rt[i].f) {
                build.push_back(rt[i].t);
                count --;
                count1 ++;
            }

        }
    }
    cout<<ans<<endl;
    cout<<count1<<endl;
    std::for_each(build.begin(), build.end(), [&](int item) {
        cout<<item<<" ";
    });
    puts("");
    cout<<count<<endl;
    if (count) {
        std::for_each(xian.begin(), xian.end(), [&](pair<int ,int> &item) {
            if (item.first)
                cout<<item.first<<" "<<item.second<<endl;
        });
    }
    return 0;
}