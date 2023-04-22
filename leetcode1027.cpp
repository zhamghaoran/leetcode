#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(1001,vector<int> (501,0));
        vector<vector<int>> dp1(1001,vector<int> (501,0));
        int ans = 0;
        for (int i = 1;i < nums.size();i ++) {
            for (int j = i - 1;j >= 0;j --) {
                if (nums[i] >= nums[j]) {
                    int cha = nums[i] - nums[j];
                    dp[i][cha] = max(dp[i][cha],dp[j][cha] + 1);
                    ans = max(dp[i][cha],ans);
                }
            }
        }
        std::reverse(nums.begin(), nums.end());
        for (int i = 1;i < nums.size();i ++) {
            for (int j = i - 1;j >= 0;j --) {
                if (nums[i] >= nums[j]) {
                    int cha = nums[i] - nums[j];
                    dp1[i][cha] = max(dp1[i][cha],dp1[j][cha] + 1);
                    ans = max(dp1[i][cha],ans);
                }
            }
        }
        return ans + 1;
    }
};
int main() {
    vector<int> qaq = {9,4,7,2,10};
    cout<<(new Solution)->longestArithSeqLength(qaq);
    return 0;
}