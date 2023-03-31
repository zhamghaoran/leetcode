#include "bits/stdc++.h"

using namespace std;
int val[100010];
int dp[1010][1010];
int sum[100010];

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &val[i]);
        sum[i] = sum[i - 1] + val[i];
    }


    for (int i = 1; i < a; i++) {
        for (int j = 1; j + i <= a ; j++) {
            int l = j;
            int r = j + i ;
            dp[l][r] = 0x3f3f3  f3f;
            for (int z = l; z < r; z++) {
                dp[l][r] = min(dp[l][r], dp[l][z] + dp[z + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }

    cout << dp[1][a];
    return 0;
}