#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1]);
            dp[i + 1][1] = max(dp[i][0] + nums[i], dp[i][1]);
        }
        return max(dp[nums.size()][1], dp[nums.size()][0]);
    }
};

int main() {
    return 0;
}