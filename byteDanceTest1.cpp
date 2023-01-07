#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findProphet(int n, vector<vector<int>> &trust) {
        vector<int> cnt(n + 1);
        for (auto i: trust) {
            cnt[i[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == n - 1) {
                bool faq = false;
                for (auto j: trust) {
                    if (j[0] == i) {
                        faq = true;
                        break;
                    }
                }
                if (!faq) {
                    return i;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> val = {{1, 2},{2,1}};
    cout << (new Solution)->findProphet(2, val);
    return 0;
}