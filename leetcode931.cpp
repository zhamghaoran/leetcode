#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        vector<vector<int>> dp (matrix.size() + 1,vector<int>(matrix.size() + 1,0x3f3f3f3f)) ;
        int ans = 0x3f3f3f3f;
        int a = matrix.size() - 1;
        for (int i = 0;i <= a;i ++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1;i <= a;i ++) {
            for (int j = 0;j <= a;j ++) {
                if (j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + matrix[i][j]);
                }
                dp[i][j] = min(dp[i][j],dp[i - 1][j] + matrix[i][j]);
                if (j + 1 <= a)
                    dp[i][j] = min(dp[i][j],dp[i - 1][j + 1] + matrix[i][j]);
            }
        }
        for (int i = 0;i <= a;i ++) {
            ans = min(ans,dp[a][i]);
        }
        return ans;

    }
};

int main() {
    return 0;
}