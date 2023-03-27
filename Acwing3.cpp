#include "bits/stdc++.h"
using namespace std;
int v[100010];
int w[100010];
int dp[1000010];
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) {
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i <= a;i ++) {
        for (int j = v[i];j <= b;j ++) {
            dp[j] = max(dp[j - v[i]] + w[i],dp[j]);
        }
    }
    cout<<dp[b];
    return 0;
}