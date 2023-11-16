#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= threshold && nums[i] % 2 == 0) dp[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > threshold) {
                continue;
            }
            if (nums[i] % 2 != nums[i + 1] % 2 && nums[i + 1] <= threshold) {
                dp[i + 1] = dp[i] + 1;
                ans = max(ans,dp[i + 1]);
            } else if (nums[i] % 2 == 0) dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        if (nums[nums.size() - 1] % 2 == 0 && nums[nums.size() - 1] <= threshold) ans = max(ans,dp[nums.size() - 1]);
        return ans;
    }
};

int main() {
    vector<int> faq = {2};
    cout << (new Solution)->longestAlternatingSubarray(faq, 4);
    return 0;
}