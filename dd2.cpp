#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            int j = i;
            while (s[j] == s[i]) {
                j++;
            }
            ans += (j - i + 1) / 2;
            i = j;
        }
    }
    cout << ans;
    return 0;
}