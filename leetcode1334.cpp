#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, val, nex;
    } rt[100010];
    int head[100010];
    int cnt;
    vector<bool> vis;

    void add(int x, int y, int z) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].val = z;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int maxx;
    int ans;

    void dfs(int x, int dis) {
        for (int i = head[x]; i; i = rt[i].nex) {
            if (!vis[rt[i].t]) {
                if (dis + rt[i].val <= maxx) {
                    ans++;
                    vis[rt[i].t] = true;
                    dfs(rt[i].t, dis + rt[i].val);
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        for (auto i: edges) {
            add(i[0], i[1], i[2]);
            add(i[1], i[0], i[2]);
        }
        maxx = distanceThreshold;
        vector<pair<int, int>> anss;
        for (int i = 0; i < n; i++) {
            vis = vector<bool>(n, false);
            vis[i] = true;
            ans = 0;
            dfs(i, 0);
            if (i == 32) cout<<ans<<endl;
            if (i == 33) cout<<ans<<endl;
            anss.emplace_back(ans, i);
        }
        std::sort(anss.begin(), anss.end(), [&](const pair<int, int> a, const pair<int, int> b) -> bool {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        return anss[0].second;
    }
};

int main() {

    vector<vector<int>> faq = {{0, 1, 3},
                               {1, 2, 1},
                               {1, 3, 4},
                               {2, 3, 1}};
    cout << (new Solution)->findTheCity(4, faq, 4);
    return 0;
}