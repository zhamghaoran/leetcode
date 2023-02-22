#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int a = piles.size();
        int dp[a + 1][a + 1];
        memset(dp,0,sizeof dp);
        int sum = 0;
        for (int i = a - 1;i >= 0;i --) {
            sum += piles[i];
            for (int M = 1;M <= a;M ++) {
                if (i + M * 2 >= a) {
                    dp[i][M] = sum;
                } else {
                    for (int x = 1;x <= 2 * M;x ++) {
                        dp[i][M] = max(dp[i][M],sum - dp[i + x][max(x,M)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
int main() {
    return 0;
}