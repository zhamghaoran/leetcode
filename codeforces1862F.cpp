#include "bits/stdc++.h"
#define int long long
using namespace std;

vector<int> val;
int w, f;
int n;
int sum;
vector<int> dp;

void init() {
    dp = vector<int>(1000010, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= val[i]; j--) {
            dp[j] = max(dp[j - val[i]] + val[i], dp[j]);
        }
    }
    for (int i = 1; i <= sum; i++) {
        if (!dp[i]) {
            dp[i] = dp[i - 1];
        }
    }
}

bool pd(int x) {
    int wa = x * w;
    int fi = x * f;
    if (wa > 1000010 || fi > 1000010)
        return true;
    if (sum - dp[wa] <= fi || sum - dp[fi] <= wa) return true;
    return false;
}

void solve() {
    scanf("%lld%lld", &w, &f);
    scanf("%lld", &n);
    sum = 0;
    val = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
        sum += val[i];
    }
    init();
    int l = 1;
    int r = (sum / w + sum / f) + 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pd(mid)) {
            r = mid;
        } else l = mid + 1;
    }
    printf("%lld\n", l);
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}