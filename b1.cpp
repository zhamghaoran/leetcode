#include "bits/stdc++.h"

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'P') {
            if (b[i] == 'P') {

            } else if (b[i] == 'R') {
                ans += 1;
            } else {
                ans -= 1;
            }
        } else if (a[i] == 'R') {
            if (b[i] == 'P') {
                ans -= 1;
            } else if (b[i] == 'R') {
                ans += 1;
            } else {

            }
        } else {
            if (b[i] == 'P') {
                ans += 1;
            } else if (b[i] == 'R') {
                ans -= 1;
            } else {

            }
        }
    }
    cout<<ans;
    return 0;
}