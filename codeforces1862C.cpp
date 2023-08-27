#include "bits/stdc++.h"

using namespace std;

void solve() {
    int a;
    cin >> a;
    vector<int> faq(a + 10);
    for (int i = 1; i <= a; i++)
        scanf("%d", &faq[i]);
    if (faq[1] != a) {
        cout << "No" << endl;
        return;
    }
    for (int i = 1; i <= a; i++) {
        int len = faq[i] - i;
        if (len < 0)
            continue;
        if (i + len <= a) {
            if (faq[i + len] >= i && faq[i + len + 1] < i) {
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        } else {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
