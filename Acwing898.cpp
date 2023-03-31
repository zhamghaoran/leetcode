#include "bits/stdc++.h"

using namespace std;
int val[1010][1010];
int dp[1010][1010];

int main() {
    int a;
    cin >> a;
    memset(val, -0x3f, sizeof val);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= i; j++) {
            ::scanf("%d", &val[i][j]);
        }
    }
    ::memset(dp, -0x3f, sizeof dp);
    dp[1][1] = val[1][1];

    for (int i = 2; i <= a; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1]) + val[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= a; i++)
        ans = max(ans, dp[a][i]);
    cout << ans;
    return 0;
}