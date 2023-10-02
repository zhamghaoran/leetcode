#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(2, -0x3f3f3f));
        int minn1 = 0; // 未购入状态
        int minn2 = -prices[0];   // 购入状态
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i][0], minn1 - prices[i]);
            dp[i][1] = max(dp[i][1], minn2 + prices[i]);
            minn1 = max(minn1, dp[i][1]);
            minn2 = max(minn2, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};

int main() {
    vector<int> faq = {1,2,3,4,5};
    cout << (new Solution)->maxProfit(faq);
    return 0;
}