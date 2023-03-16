#include "bits/stdc++.h"
using namespace std;
long long qk(long long x,long long y) {
    long long ans = 1;
    long long mod = y + 2;
    while (y) {
        if (y & 1)
            ans *= x,ans %= mod;
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ans;
}
int main() {
    int a;
    cin>>a;
    while (a --) {
        int x,y;
        cin>>x>>y;
        if (__gcd(x,y) != 1) {
            cout<<"impossible\n";
            continue;
        }
        cout<<qk(x,y - 2)<<endl;
    }
    return 0;
}