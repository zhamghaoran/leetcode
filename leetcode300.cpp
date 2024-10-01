#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int ans = 1;
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}