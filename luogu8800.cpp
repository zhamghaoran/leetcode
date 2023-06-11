#include "bits/stdc++.h"
#define int long long
using namespace std;
int val[200100];
int val1[200010];


signed main() {
    int a, b;
    cin >> a >> b;
    int l = 0x7f7f7f7f;
    int r = 0;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &val[i]), l = min(l, val[i]);
    }
    for (int i = 1; i <= a; i++)
        scanf("%lld", &val1[i]), r = max(r, val[i] + val1[i]);

    auto pd = [&](int x) -> bool {
        long long sum = 0;
        for (int i = 1; i <= a; i++) {
            if (x < val[i])
                continue;
            if (x <= val[i] + val1[i]) {
                sum += x - val[i];
            } else {
                return false;
            }
        }
        return sum <= b;
    };
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pd(mid)) {
            l = mid + 1;
        } else r = mid;
    }
    cout << l - 1;
    return 0;
}


