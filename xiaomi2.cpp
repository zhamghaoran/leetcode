#include <bits/stdc++.h>

using namespace std;

int judge(vector<int> a, vector<int> b) {
    int now = -99999;
    for (int i = 1; i < a.size(); i++) {
        if (now <= a[i] && now <= b[i]) {
            now = min(a[i], b[i]);
        } else if (now <= a[i]) {
            now = a[i];
        } else if (now <= b[i]) {
            now = b[i];
        } else {
            return 0;
        }
    }
    return 1;
}

int judge1(vector<int> a, vector<int> b) {
    int now = 999999;
    for (int i = 1; i < a.size(); i++) {
        if (now >= a[i] && now >= b[i]) {
            now = max(a[i], b[i]);
        } else if (now >= a[i]) {
            now = a[i];
        } else if (now >= b[i]) {
            now = b[i];
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a = vector<int>(n + 1, 0);
        vector<int> b = vector<int>(n + 1, 0);
        int x;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[i] = x;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            b[i] = x;
        }
        int res = 0;
        res = max(res, judge(a, b));
        res = max(res, judge(b, a));
        res = max(res, judge1(a, b));
        res = max(res, judge1(b, a));
        if (res == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
//YES
//NO