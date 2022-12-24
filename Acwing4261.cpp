#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int a;
    string b;
    cin >> a >> b;
    int ans = 0;
    int be = 0;
    int en = 0;
    auto max = [&](int a, int b) -> int { return a > b ? a : b; };
    for (int i = 0; i < b.size() ; i++) {
        while (be < i && b[i - be - 1] != b[i])
            be++;
        while (i + en + 1 < b.size() && b[i + en + 1] != b[i])
            en++;
        ans += be * en + max(be - 1, 0) + max(en - 1, 0);
        be = 0;
        en = 0;
    }
    cout << ans;
    return 0;
}