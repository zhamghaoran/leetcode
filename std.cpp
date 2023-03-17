#include "bits/stdc++.h"
using namespace std;
void solve() {
    int a;
    cin>>a;
    vector<int> val(a);
    for (int i = 0;i < a;i ++)
        cin>>val[i];
    int gcd = __gcd(val[0],val[1]);
    for (int i = 2; i < a;i ++) {
        gcd = __gcd(gcd,val[i]);
    }
    cout<<val[a - 1] / gcd<<endl;
}
int main() {
    int t;
    cin>>t;
    while (t --) {
        solve();
    }
}