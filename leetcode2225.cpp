#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        unordered_map<int, int> losemap;
        vector<vector<int>> ans(2);
        for (int i = 0; i < matches.size(); i++) {
            if (!losemap.count(matches[i][0])) {
                losemap[matches[i][0]] = 0;
            }
            losemap[matches[i][1]]++;
        }
        for (auto &[k, v]: losemap) {
            if (v < 2) {
                ans[v].push_back(k);
            }
        }
        std::sort(ans[0].begin(), ans[0].end());
        std::sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};

int main() {

}