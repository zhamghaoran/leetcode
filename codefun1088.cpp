#include <bits/stdc++.h>

using namespace std;
int val[100010];
int a;

bool pd(long long x) {
    for (int i = 1; i <= a; i++) {
        if (val[i] > x) {
            x -= (val[i] - x);
        } else {
            x += (x - val[i]);
        }
        if (x < 0)
            return false;
    }
    return true;
}

int main() {
    cin >> a;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &val[i]);
    }
    int l = 1;
    int r = 0x3f3f3f3f;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pd(mid)) {
            r = mid;
        } else l = mid + 1;
    }
    cout << l;
    return 0;
}