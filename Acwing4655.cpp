#include "bits/stdc++.h"
#define int long long
using namespace std;
int val[1000010];
int chafen[1000010];
int neww[1000010];
signed main() {
    int a;
    scanf("%lld",&a);
    for (int i = 1;i <= a;i ++) {
        scanf("%lld",&val[i]);
    }
    int b;
    cin>>b;
    int x,y;
    for(int i = 1;i <= b;i ++) {
        scanf("%lld%lld",&x,&y);
        chafen[x] ++;
        chafen[y + 1] --;
    }
    long long ans1 = 0;
    for (int i = 1;i <= a;i ++) {
        neww[i] = neww[i  - 1] + chafen[i];
        ans1 += neww[i] * val[i];
    }
    sort(neww + 1,neww + 1 + a);
    sort(val + 1,val + 1 + a);
    long long ans2 = 0;
    for (int i = a;i >= 1;i --) {
        ans2 += neww[i] * val[i];
    }
    cout<<ans2 - ans1;
    return 0;
}