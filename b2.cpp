#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool res = true;
        if (b % a != 0) {
            if (c - (c % a) < b) {
                res = false;
            }
        }
        if (res) {
            cout << ceil(1.00 * b / a) << " " << c / a << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}