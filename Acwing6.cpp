#include "bits/stdc++.h"

using namespace std;
int cnt;
int val[100010];
int w[100010];
int dp[100100];
int main() {
    int a, b;
    cin >> a >> b;
    int x,y,z;
    for (int i = 1; i <= a; i++) {
        scanf("%d%d%d", &x, &y, &z);
        int now = 1;
        while (now <= z) {
            val[++ cnt] = y * now;
            w[cnt] = x * now;
            z -= now;
            now <<= 1;
        }
        if (z) {
            val[++ cnt] = y * z;
            w[cnt] = x * z;
        }
    }

    for (int i = 1;i <= cnt;i ++) {
        for (int j = b;j >= w[i];j --) {
            dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
        }
    }
    cout << dp[b];
    return 0;
}