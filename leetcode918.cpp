#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        vector<int> dp(nums.size(), -0x3f3f3f3f);
        vector<int> maxl(nums.size(), -0x3f3f3f3f);
        dp[0] = nums[0];
        maxl[0] = dp[0];
        int maxx = -0x3f3f3f3f;
        int add = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
            maxl[i] = max(maxl[i - 1], add + nums[i]);
            maxx = max(maxx, dp[i]);
            add += nums[i];
        }
        add = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            maxx = max(maxx, maxl[i] + add);
            add += nums[i];
        }
        return maxx;
    }
};

int main() {
    vector<int> faq = {-2, 2, -2, 9};
    cout << (new Solution)->maxSubarraySumCircular(faq);
    return 0;
}