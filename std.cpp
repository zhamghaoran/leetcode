#include <bits/stdc++.h>

#define int long long
using namespace std;
int sum;

signed main() {
    int a;
    cin >> a;
    int maxx = -100000000000;
    int minn = 100000000000;
    int x = 0;
    for (int i = 1; i <= a; i++) {
        cin >> x;
        sum += x;
        maxx = max(maxx, sum);
        minn = min(minn, sum);
    }
    cout << maxx - minn;
    return 0;
}
/*
6
2 -5 1 -4 3 -2
 *
 */