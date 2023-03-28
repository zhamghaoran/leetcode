#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    int a;
    cin>>a;
    int ans = 0;
    int x;
    if (a & 1)
        x = a >> 1;
    else
        x = a / 2 - 1;
    for (int i = 1;i < a;i ++) {
        if (((i * i) % a) <= x)
            ans ++;
    }
    cout<<ans;
    return 0;
}