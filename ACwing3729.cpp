#include "bits/stdc++.h"
using namespace std;

void solve() {
    int a;
    cin>>a;
    vector<int> val(a + 1,0);
    int x;
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&x);
        x = min(x,i);
        if (x) {
            val[i - x] ++;
            val[i] --;
        }
    }
    vector<int> ans(a + 1,0);
    int sum = val[0];
    for (int i = 1;i <= a;i ++) {
        ans[i] = sum;
        sum += val[i];
    }
    for (int i = 1;i <= a;i ++) {
        if (ans[i])
            cout<<1<<" ";
        else cout<<0<<" ";
    }
    puts("");
}
int main() {
    int t;
    cin>>t;
    while (t --)
        solve();
    return 0;

}