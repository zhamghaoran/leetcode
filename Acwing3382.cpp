#include "bits/stdc++.h"
using namespace std;
const int mod = 1000000000;
int main() {
    int a;
    cin>>a;
    vector<int> mi;
    int x = 1;
    vector<int> dp(a + 10,0);
    dp[0] = 1;
    while (x <= a) {
        mi.push_back(x);
        x *= 2;
    }
    for (int i : mi) {
        for (int j = i;j <= a;j ++ ) {
            dp[j] += dp[j - i];
            dp[j] %= mod;
        }
    }
    cout<<dp[a];
    return 0;
}