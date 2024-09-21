#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, c;
        cin >> n >> a >> c;
        vector<int> val;
        int x;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= a; i++) {
            scanf("%d", &x);
            val.push_back(x);
        }
        dp[0] = 1;
        for (int i = 0; i < val.size(); i++) {
            for (int j = n; j >= val[i]; j--) {
                dp[j] = max(dp[j - val[i]], dp[j]);
            }
        }
        bool ans = false;
        for (int i = n; i >= n - c; i--) {
            if (dp[i]) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}