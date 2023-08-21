#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    cin >> a;
    int x, y, z;
    for (int i = 1; i <= a; i++) {
        scanf("%d%d%d", &x, &y, &z);
        if (z & 1) {
            x += z / 2 + 1;
        } else
            x += z / 2;
        y += z / 2;
        if (x > y) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;

}