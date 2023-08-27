#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<pair<int, int>, int> old;
        int a;
        cin >> a;
        int b;
        int x, y;
        int ans = 0;
        for (int i = 1; i <= a; i++) {
            scanf("%d", &b);
            map<pair<int, int>, int> neww;
            for (int j = 1; j <= b; j++) {
                scanf("%d%d", &x, &y);
                neww[make_pair(x, y)]++;
            }
            for (auto &[k, v]: neww) {
                if (old.count(k)) {
                    v += old[k];
                }
                ans = max(ans, v);
            }
            old = neww;
        }
        cout << ans << endl;
    }
    return 0;
}
