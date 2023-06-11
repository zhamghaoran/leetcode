#include "bits/stdc++.h"

#define int long long
using namespace std;
int day[100010];
int val[100010];

int max(int a, int b) {
    return a > b ? a : b;
}

signed main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        cin >> day[i] >> val[i];
    }
    int ans = 0;
    int now = 0;
    for (int i = 1; i <= a; i++) {
        if (day[i] > now)
            now = day[i];
        ans += max(min(b - now + 1, val[i]), 0);
        now += val[i];
    }
    cout << ans;
    return 0;
}