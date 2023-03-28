#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
    int a;
    cin>>a;
    int x = 1;
    for (int i = 2;i * i <= a ;i ++) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) {
                a /= i,cnt ++;
            }
            if (cnt & 1)
                x *= i;
        }
    }
    if (a > 1)
        x *= a;
    cout<<x;
    return 0;
}