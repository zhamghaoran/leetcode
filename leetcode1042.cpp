#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<int> ans(n, 0);
        vector<vector<int>> faq(n + 10, vector<int>());
        std::for_each(paths.begin(), paths.end(), [&](vector<int> item) {
            int be = item[0];
            int se = item[1];
            faq[be].push_back(se);
            faq[se].push_back(be);
        });
        for (int i = 1; i <= n; i++) {
            vector<int> vis(5, 0);
            std::for_each(faq[i].begin(), faq[i].end(), [&](const auto &item) {
                if (ans[item - 1] != 0) {
                    vis[ans[item - 1]] = 1;
                }
            });
            for (int j = 1; j <= 4; j ++) {
                if (!vis[j]) {
                    ans[i - 1] = j;
                    break;
                }

            }
        }
        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> faq = {{1, 2},
                               {3,4}};
    vector<int> ans = (new Solution)->gardenNoAdj(n, faq);
    std::for_each(ans.begin(), ans.end(), [&](const auto &item) {
        cout<<item<<" ";
    });
    return 0;
}