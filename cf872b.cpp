#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        ::scanf("%d%d", &a, &b);
        vector<int> val;
        int x;
        for (int i = 1; i <= a * b; i++) {
            scanf("%d", &x);
            val.push_back(x);
        }
        std::sort(val.begin(), val.end(), [&](const int a, const int b) -> bool {
            return a > b;
        });
        long long ans = 0;
        x = min(a, b);
        long long a1 = max((x - 1), 0) * (val[0] - val[a * b - 2]);
        long long a2 = max(x - 1,0) * (val[1] - val[a * b - 1]);
        ans += max(a1,a2);
        ans += (a * b - x) * (val[0] - val[a * b - 1]);
        cout << ans << endl;
    }
    return 0;
}