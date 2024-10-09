#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;

    vector<vector<int>> permute(vector<int> &nums) {
        vis = vector<bool>(nums.size(), false);
        dfs(0, nums.size(), vector<int>(nums.size(), 0), nums);
        return ans;
    }

    void dfs(int now, int end, vector<int> tem, vector<int> nums) {
        if (now == end) {
            ans.push_back(tem);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!vis[i]) {
                    tem[now] = nums[i];
                    vis[i] = true;
                    dfs(now + 1, end, tem, nums);
                    vis[i] = false;
                }
            }
        }
    }
};

int main() {
    vector<int> faq = {1, 2, 3};
    auto ans = (new Solution)->permute(faq);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}