#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = amount; j >= 0; j--) {
                int maxCount = amount / coins[i];
                for (int x = 1; x <= maxCount; x++) {
                    if (j - x * coins[i] >= 0) {
                        dp[j] = min(dp[j], dp[j - x * coins[i]] + x);
                    }

                }
            }
        }
        if (dp[amount] == 0x3f3f3f3f) {
            return -1;
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    cout << (new Solution)->coinChange(coins, 11);
    return 0;

}