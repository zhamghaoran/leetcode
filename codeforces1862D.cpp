#include "bits/stdc++.h"

using namespace std;
vector<long long> qaq;


void solve() {
    long long a;
    scanf("%lld", &a);
    long long l = 1;
    long long r = 0x7f7f7f7f;
    while (l < r) {
        long long mid = (l + r) >> 1;
        long long ans = mid * (mid - 1) / (long long) 2;
        if (ans == a) {
            printf("%lld\n", mid);
            return;
        } else if (ans < a) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l = a - (l - 2) * (l - 1) / 2 + l - 1;
    printf("%lld\n", l);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}