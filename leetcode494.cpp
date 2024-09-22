#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int de = (sum - target) / 2;
        if (de < 0 || (sum - target) < 0 || (sum - target) % 2 != 0) {
            return 0;
        }
        vector<vector<int>> dp = vector<vector<int>>(100, vector<int>(1001, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            for (int j = de; j >= 0; j--) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[nums.size()][de];
    }
};

int main() {
    vector<int> nums = {1000};
    cout << (new Solution)->findTargetSumWays(nums, -1000);
    return 0;
}