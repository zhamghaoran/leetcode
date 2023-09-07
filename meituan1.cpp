#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
    int a;
    cin >> a;
    vector<int> val(a + 1);
    int faq = 0;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &val[i]);

        faq += val[i];
    }
    int maxx = 0;
    int sum = 0x3f3f3f3f;
    for (int i = 2; i <= a; i++) {
        if (val[i] * val[i - 1] > maxx) {
            maxx = val[i] * val[i - 1];
            sum = val[i] + val[i - 1];
        } else if (val[i] * val[i - 1] == maxx) {
            sum = min(sum, val[i] + val[i - 1]);
        }
    }
    cout << faq - sum + maxx;
    return 0;
}
