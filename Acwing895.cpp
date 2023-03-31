#include "bits/stdc++.h"

using namespace std;
int val[1000010];
int dp[100010];
int ans;

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &val[i]);
        dp[i] = 1;
    }
    for (int i = 1; i <= a; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (val[i] > val[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}