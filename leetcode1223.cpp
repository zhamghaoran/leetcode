#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    int dieSimulator(int n, vector<int> &rollMax) {
        int dp[n + 1][7][16];
        memset(dp,0,sizeof dp);
        const int mod = 1e9 + 7;
        for (int i = 0;i < 6;i ++) {
            dp[1][i][1] = 1;
        }
        for (int i = 2;i <= n; i ++) {
            for (int j = 0;j < 6;j ++) {
                for (int k = 1;k <= rollMax[j];k ++) {
                    for (int p = 0;p < 6;p ++) {
                        if (p != j) {
                            dp[i][p][1] = (dp[i][p][1] + dp[i - 1][j][k]) % mod;
                        } else if (k + 1 <= rollMax[j])
                            dp[i][p][k + 1] += (dp[i][p][k + 1] + dp[i - 1][j][k]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0;i < 6;i ++) {
            for (int j = 1;j <= rollMax[i];j ++) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}