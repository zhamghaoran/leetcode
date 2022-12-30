#include "bits/stdc++.h"
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    vector<int> dp(a + 1,0);
    long long ans = 0;
    for (int i = 1;i <= a;i ++) {
        dp[i] = dp[i / 10] + (i % 10 == b);
        ans += dp[i];
    }
    cout<<ans;
    return 0;
}