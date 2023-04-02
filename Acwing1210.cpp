#include "bits/stdc++.h"
#define int long long
using namespace std;
int ans;
signed main() {
    int a;
    cin>>a;
    vector<int> val(a + 1);
    for (int i = 1;i <= a;i ++) {
        scanf("%lld",&val[i]);
    }
    for(int i = 1;i <= a;i ++) {
        int maxx = 0;
        int minn = 0x3f3f3f;
        for (int j = i;j <= a;j ++) {
            maxx = max(maxx,val[j]);
            minn = min(minn,val[j]);
            if (maxx - minn == j - i)
                 ans ++;
        }
    }
    cout<<ans;
    return 0;
}