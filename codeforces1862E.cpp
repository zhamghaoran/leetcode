#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve() {
    int n, m, d;
    scanf("%lld%lld%lld", &n, &m, &d);
    int ans = 0;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
    }
    priority_queue<int> faq;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (val[i] > 0 && faq.size() <= m) {
            if (faq.size() >= m) {
                cur += faq.top();
                faq.pop();
            }
            cur += val[i];
            ans = max(ans, cur - i * d);
            faq.push(-val[i]);
        }
    }
    printf("%lld\n", ans);
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}