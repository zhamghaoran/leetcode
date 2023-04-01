#include "bits/stdc++.h"

using namespace std;
int a;
int val[100010];
int ans;
int sum;
int dp[100010];

int main() {
    cin >> a;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &val[i]);
        sum += val[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = sum; j >= val[i]; j--) {
            if (dp[j - val[i]] == 1 && dp[j] != 1) {
                dp[j] = 1;
                ans++;
            }
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j <= sum -  val[i]; j++) {
            if (dp[j + val[i]] == 1 && dp[j] != 1) {
                dp[j] = 1;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}