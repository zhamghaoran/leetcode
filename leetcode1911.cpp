#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long dp[100010][2][2];

    long long maxAlternatingSum(vector<int> &nums) {
        long long ans = -0x3f3f3f3f;
        for (int i = 0; i < nums.size(); i++) {
            dp[i + 1][0][0] = max(dp[i][0][0], dp[i][1][0]);
            dp[i + 1][0][1] = max(dp[i][0][1], dp[i][1][1]);
            dp[i + 1][1][1] = max(dp[i][1][0], dp[i][0][0]) - nums[i];
            dp[i + 1][1][0] = max(dp[i][1][1], dp[i][0][1]) + nums[i];
            ans = max(ans, max(dp[i + 1][1][1], max(dp[i + 1][1][0], max(dp[i + 1][0][0], dp[i + 1][0][1]))));
        }
        return ans;
    }
};

int main() {
    return 0;
}