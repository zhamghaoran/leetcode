#include "bits/stdc++.h"

#define int long long
using namespace std;

signed main() {
    int a;
    cin >> a;
    vector<int> val(a + 1);
    vector<int> sum(a + 1);
    for (int i = 1; i <= a; i++)
        scanf("%lld", &val[i]),sum[i] = sum[i - 1] + val[i];
    if (sum[a] % 3 || a < 3) {
        cout<<0;
        return 0;
    }
    int tar = sum[a] / 3;
    int cnt = 0;
    int ans = 0;
    for (int i = 1;i < a;i ++) {
        if (sum[i] == tar * 2)
            ans += cnt;
        if (sum[i] == tar) {
            cnt ++;
        }
    }
    cout<<ans;
    return 0;
}