#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int dp[100][100];
    int sum[100];
    int mergeStones(vector<int>& stones, int k) {
        int a = stones.size();
        memset(sum,0x3f,sizeof sum);
        for (int i = 0;i < a;i ++) {
            sum[i + 1] += sum[i] + stones[i];
            dp[i + 1][i + 1] = 0;
        }
        for (int i = 1;i * k <= a;i ++) {
            for (int l = 1;l <= a - k;l ++) {
                int r = l + k;
                for (int mid = l;mid < r;mid ++) {
                    dp[l][r] = max(dp[l][r],dp[l][mid] + dp[mid + 1][r] + sum[r] - sum[l - 1]);
                }
            }
        }
        return dp[1][a];
    }

};
int main() {

    return 0;
}