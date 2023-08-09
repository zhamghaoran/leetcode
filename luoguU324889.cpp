#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    string c;
    for (int i = 1; i <= a; i++) {
        cin >> c;
        for (int j = 0; j <= c.length(); j++) {
            if (c[j] <= 'z' && c[j] >= 'a') {
                c[j] = int(c[j]) + 7;
                if (c[j] > 'z') {
                    c[j] = c[j] - 'z' + 'a';
                }
            } else {
                c[j] = int(c[j]) + 7;
                if (c[j] > 'Z') {
                    c[j] = c[j] - 'Z' + 'A';
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}