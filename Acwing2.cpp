#include "bits/stdc++.h"
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    vector<int> v;
    vector<int> val;
    for (int i = 1; i <= a;i ++) {
        int x,y;
        cin>>x>>y;
        v.push_back(x);
        val.push_back(y);
    }
    vector<int> dp(b + 1);
    for (int i = 1;i <= a;i ++) {
        for (int j = b;j >= v[i - 1];j --) {
            dp[j] = max(dp[j],dp[j - v[i - 1]] + val[i - 1]);
        }
    }
    cout<<dp[b];
    return 0;
}