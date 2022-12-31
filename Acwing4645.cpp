#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<int,int> last;
    int a,b,x;
    cin>>a>>b>>x;
    vector<int> val(a + 1);
    vector<int> dp(a + 1);
    for (int i = 1;i <= a;i ++) {
        cin>>val[i];
        last[val[i]] = i;
        dp[i] = max(dp[i - 1],last[x ^ val[i]]);
    }
    int l,r;
    for (int i = 1;i <= b;i ++) {
        cin>>l>>r;
        if (l <= dp[r])
            puts("yes");
        else
            puts("no");
    }
    return 0;
}