#include "bits/stdc++.h"

using namespace std;
int dp[101000];

int main() {
    int a, b;
    cin >> a >> b;
    int x;
    vector <vector<int>> val;
    vector <vector<int>> wei;
    val.emplace_back();
    wei.emplace_back();
    for (int i = 1; i <= a; i++) {
        scanf("%d", &x);
        vector<int> vall;
        vector<int> weii;
        int xx, yy;
        for (int j = 1; j <= x; j++) {
            ::scanf("%d%d", &xx, &yy);
            weii.push_back(xx);
            vall.push_back(yy);
        }
        val.push_back(vall);
        wei.push_back(weii);
    }

    for (int i = 1; i <= a; i++) {
        for (int j = b;j >= 0;j --)  {
            for (int z = 0;z < val[i].size();z ++) {
                if (j >= wei[i][z])
                    dp[j] = max(dp[j],dp[j - wei[i][z]] + val[i][z]);
            }
        }
    }
    cout<<dp[b];
    return 0;
}