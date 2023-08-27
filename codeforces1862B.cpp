#include "bits/stdc++.h"

using namespace std;

void solve() {
    int a;
    cin >> a;
    vector<int> faq(a + 1);
    for (int i = 1; i <= a; i++) {
        scanf("%d", &faq[i]);
    }
    vector<int> ans;
    ans.push_back(faq[1]);
    for (int i = 2; i <= a; i++) {
        if (faq[i] >= faq[i - 1]) {
            ans.push_back(faq[i]);
        } else {
            ans.push_back(faq[i]);
            ans.push_back(faq[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    puts("");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}