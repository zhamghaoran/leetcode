#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    int a;
    cin>>a;
    int ans = 0;
    for (int i = 2;i * i <= a;i ++) {
        if (a % i == 0) {
            while (a % i == 0){
                a /= i;
            }
            ans ++;
        }
    }
    if (a > 1)
        ans ++;
    cout<<ans;
    return 0;
}