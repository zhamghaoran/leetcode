#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct e {
        int f, t, nex;
    } rt[100010];
    int cnt;
    int head[100010];
    double ans[100010];

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int siz[100010];

    void dfs1(int x, int f) {
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                dfs1(rt[i].t, x);
                siz[x]++;
            }
        }
    }

    void dfs(int x, int f, int t) {
        if (t == 0)
            return;
        if (siz[x] == 0)
            return;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                ans[rt[i].t] = ans[x] / siz[x];
                dfs(rt[i].t, x, t - 1);
            }
        }
        ans[x] = 0;
    }

    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        cnt = 0;
        std::for_each(edges.begin(), edges.end(), [&](const vector<int> &item) {
            add(item[0], item[1]);
            add(item[1], item[0]);
        });
        dfs1(1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = 0.00;
        ans[1] = 1.00;
        dfs(1, 0, t);
        return ans[target];
    }
};

int main() {
    vector<vector<int>> faq = {{1, 2},
                               {2, 3},
                               {1, 4},
                               {1, 5},
                               {4, 6},
                               {1, 7},
                               {8, 7}};
    cout << (new Solution)->frogPosition(8, faq, 7, 7);
    return 0;
}