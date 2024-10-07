#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (long long i = 1;; i++) {
            if (i * i > n) {
                break;
            }
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - nums[j]] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    cout << (new Solution)->numSquares(8935);
    return 0;
}