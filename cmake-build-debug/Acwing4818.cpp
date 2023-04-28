#include <bits/stdc++.h>
#define int long long
using namespace std;
int val[1000010];
signed main() {
    int a;
    cin>>a;
    for (int i = 1;i <= a;i ++)
        cin>>val[i];
    sort(val + 1,val + 1 + a,[&](int a,int b) -> bool {return a > b;});
    int ans = 0;
    int  num;
    for (int i = 1;i <= a;i ++) {
        if (ans <= val[i] *  i){
            ans = val[i] * i;
            num = val[i];
        }
    }
    cout<<ans<<" "<<num;
    return 0;
}