#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
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

    int fa[100010];
    int siz[100010];
    int dp[100010];
    vector<int> ans;

    void dfs(int x, int f) {
        siz[x] = 1;
        fa[x] = f;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                dfs(rt[i].t, x);
                siz[x] += siz[rt[i].t];
                dp[x] += dp[rt[i].t] + siz[rt[i].t];
            }
        }
    }
    int a;
    void dfs2(int x, int f) {
        if (x != 0) {
            ans[x] += dp[fa[x]] - dp[x] - siz[x] + a - siz[x] + dp[x];
            dp[x] = ans[x];
        } else ans[x] = dp[x];
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                dfs2(rt[i].t, x);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        a = n;
        ans = vector<int>(n, 0);
        std::for_each(edges.begin(), edges.end(), [&](const vector<int> &val) -> void {
            add(val[0], val[1]);
            add(val[1], val[0]);
        });
        dfs(0, 0);
        dfs2(0, 0);
        return ans;
    }

};

int main() {
    vector<vector<int>> faq = {{0, 1},
                               {0, 2},
                               {2, 3},
                               {2, 4},
                               {2, 5}};
    vector<int> ans = (new Solution)->sumOfDistancesInTree(6, faq);
    std::for_each(ans.begin(), ans.end(), [&](const int val) -> void {
        cout << val << " ";
    });
    return 0;
}