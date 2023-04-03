#include "bits/stdc++.h"
#define int long long
#define mod 1000000007
using namespace std;
int mapp[100][100];
int dp[51][51][51][20];

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            scanf("%lld", &mapp[i][j]);
            mapp[i][j] ++;
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][1][mapp[1][1]][1] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int cnt = 0; cnt <= c; cnt++) {
                for (int k = 0; k <= 15; k++) {
                    // 不拿
                    dp[i][j][k][cnt] += dp[i - 1][j][k][cnt] ;
                    dp[i][j][k][cnt] %= mod;
                    dp[i][j][k][cnt] += dp[i][j - 1][k][cnt];
                    dp[i][j][k][cnt] %= mod;
                    if (k == mapp[i][j] && cnt > 0) {
                        for (int xx = 0; xx < mapp[i][j]; xx++) {
                            dp[i][j][k][cnt] += dp[i][j - 1][xx][cnt - 1] ;
                            dp[i][j][k][cnt] %= mod;
                            dp[i][j][k][cnt] += dp[i - 1][j][xx][cnt - 1];
                            dp[i][j][k][cnt] %= mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 13; i++) {
        ans += dp[a][b][i][c];
        ans %= mod;
    }
    cout << ans;
    return 0;
}