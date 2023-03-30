#include "bits/stdc++.h"

using namespace std;
int val[100010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        for (int i = 1; i <= a; i++)
            scanf("%d", &val[i]);
        int ans = -0x3f3f3f3f;
        int be = -0x3f3f3f3f;
        int af = -0x3f3f3f3f;
        vector<int> pre(a + 2, -0x3f3f3f3f);
        vector<int> suf(a + 2, -0x3f3f3f3f);
        for (int i = 1; i <= a; i++) {
            be = max(be, 0) + val[i];
            pre[i] = max(be, pre[i - 1]);
        }
        for (int i = a; i >= 1; i--) {
            af = max(af, 0) + val[i];
            suf[i] = max(suf[i - 1], af);
        }
        for (int i = 1; i <= a; i++) {
            ans = max(ans, pre[i] + suf[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}