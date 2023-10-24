#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int ans = 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(max(target,k)+ 1, 0));
        int mod = 1000000007;
        for (int i = 1; i <= k; i++) dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int z = target; z > j; z--) {
                    dp[i][z] += dp[i - 1][z - j] % mod;
                }
            }
        }
        return dp[n][target] % mod;
    }
};

int main() {
    return 0;
}