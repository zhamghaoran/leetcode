#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 0;
        auto pd = [&](int mid) -> bool {
            vector<int> dp(nums.size() + 10, 0);
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    dp[i + 2] = dp[i] + 1;
                } else {
                    dp[i + 2] = dp[i + 1];
                }
            }
            return dp[nums.size() + 1] >= k;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (pd(mid))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    vector<int> faq = {2,3,5,9};
    cout << (new Solution)->minCapability(faq, 2);
    return 0;
}