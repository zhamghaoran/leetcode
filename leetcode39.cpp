#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vis = vector<bool>(candidates.size(), false);
        vector<int> res;
        dfs(0, target, res, candidates, 0);
        return ans;
    }

    void dfs(int temsum, int tar, vector<int> res, vector<int> candidates, int lastIndex) {
        if (temsum == tar) {
            ans.push_back(res);
        } else {
            for (int i = lastIndex; i < candidates.size(); i++) {
                if (temsum + candidates[i] <= tar) {
                    vector<int> newRes = res;
                    newRes.push_back(candidates[i]);
                    dfs(temsum + candidates[i], tar, newRes, candidates, i);
                }
            }
        }
    }
};

int main() {
    vector<int> faq = {2, 3, 6, 7};
    auto res = (new Solution)->combinationSum(faq, 7);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}