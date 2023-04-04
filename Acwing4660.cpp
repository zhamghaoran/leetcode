#include "bits/stdc++.h"
#define mod 998244353
#define int long long
using namespace std;
signed main() {
    int a;
    cin>>a;
    int ans = 0;
    for (int i = 0;i < a;i ++) {
        ans += (a - 1) * i * (a - i) % mod;
        ans %= mod;
    }
    cout<<ans;
    return 0;
}