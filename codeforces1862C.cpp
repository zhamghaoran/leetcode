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
    vector<int> neww;
    neww.push_back(a);
    for (int i = a - 1; i >= 1; i--) {
        if (faq[i] > faq[i + 1]) {
            neww.push_back(i);
        }
    }
    int j = 0;
    for (int i = 1;i <= a;i ++) {
        if (i > 1 && faq[i] == faq[i - 1])
            continue;
        if (faq[i] != neww[j]) {
            cout<<"no"<<endl;
            return;
        }
        j ++;
    }
    cout << "yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1
5
5 1 1 1 1
 */