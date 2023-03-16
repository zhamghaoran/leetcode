#include "bits/stdc++.h"
#define mod 233333
using namespace std;
int main() {
    long long ans = 1;
    long long a,b;
    cin>>a>>b;
    while (b) {
        if (b & 1)
            ans *= a,ans %= mod;
        a *= a;
        a %= mod;
        ans %= mod;
        b >>= 1;
    }
    cout<<ans;
    return 0;
}