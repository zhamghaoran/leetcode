#include "bits/stdc++.h"
using namespace std;
int dp[100010];
int main() {
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i = 1;i <= 100000;i ++) {
        dp[i] = min(dp[i],dp[i - 1] + 1);
        for (int j = 1;i *(j + 1) <= 100000;j ++) {
            dp[i*(j + 1)] = min(dp[i * (j + 1)],dp[i] + 4 + j * 2);
        }
    }
    int a;
    cin>>a;
    for (int i = 1;i <= a;i ++) {
        int x;
        cin>>x;
        printf("Case #%d: %d\n",i,dp[x]);
    }

    return 0;
}