#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    cin >> a;
    while (a--) {
        int b;
        cin >> b;
        vector<int> val;
        int x;
        for (int i = 0; i < b; i++) {
            scanf("%d", &x);
            val.push_back(x);
        }
        std::sort(val.begin(), val.end());
        int ans = 0;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                int xx = lower_bound(val.begin(), val.end(), val[i] + val[j]) - val.begin();
                while (val[i] + val[j] == val[xx] && xx < b) {
                    ans++;
                    xx++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}