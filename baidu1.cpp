#include <bits/stdc++.h>

using namespace std;
const int mod = 1E9 + 7;

int getop(int cnt) {
    if (cnt & 1) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    int a;
    cin >> a;
    vector<int> val;
    int x;
    for (int i = 1; i <= a; i++) {
        cin >> x;
        val.push_back(x);
    }
    int cnt = 1;
    for (int i = 1; i < a; i++) {
        vector<int> tem;
        for (int j = 0; j < val.size() - 1; j++) {
            tem.push_back(val[j] + (val[j + 1] * getop(cnt++)) % mod);
        }
        val = tem;
    }
    cout << val[0] % mod;
    return 0;
}
