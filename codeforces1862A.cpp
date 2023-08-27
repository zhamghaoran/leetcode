#include "bits/stdc++.h"

using namespace std;

void solve() {
    char faq[1010][1010];
    int a, b;
    vector<char> qaq = {'v', 'i', 'k', 'a'};
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> faq[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            if (faq[j][i] == qaq[cnt]) {
                cnt  ++;
                break;
            }
        }
        if (cnt == 4) {
            cout<<"Yes"<<endl;
            return ;
        }
    }
    cout<<"No"<<endl;
    return;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}