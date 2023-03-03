#include "bits/stdc++.h"
#define int long long
using namespace std;
int val[100010];
signed main() {
    int a,b;
    cin>>a>>b;
    int x;
    for (int i = 1;i <= a;i ++) {
        ::scanf("%lld",&x);
        val[i] += x + val[i - 1];
    }
    int l,r;
    for (int i = 1;i <= b;i ++) {
        ::scanf("%lld%lld",&l,&r);
        ::printf("%lld\n",val[r] - val[l - 1]);
    }
    return 0;
}