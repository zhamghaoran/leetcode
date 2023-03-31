#include "bits/stdc++.h"

using namespace std;
int ans;
int dp[1010][1010];

int main() {
    int a, b;
    cin >> a >> b;
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
            }
        }
    }
    cout << dp[a][b];
    return 0;
}