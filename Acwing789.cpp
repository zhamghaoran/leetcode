#include "bits/stdc++.h"
using namespace std;
int val[100010];
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&val[i]);
    }
    int x;
    for (int i = 1;i <= b;i ++) {
        cin>>x;
        int l = lower_bound(val + 1,val + 1 + a,x) - val;
        int r = upper_bound(val + 1,val + 1 + a,x) - val;
        if(val[l] != x) {
            cout<<"-1 -1"<<endl;
        } else {
            cout<<l - 1<<" "<<r - 2<<endl;
        }
    }
    return 0;
}