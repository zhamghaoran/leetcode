#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        bool beg = false;
        int res0 = 0;
        int res1 = 0;
        for (char i: s) {
            if (i == '0' && !beg) {
                res0++;
                continue;
            }
            if (i == '0' && beg) {
                if (res1 <= res0) {
                    ans = max(ans, res1);
                }
                beg = false;
                res1 = 0;
                res0 = 1;
                continue;
            }
            if (i == '1' && !beg) {
                beg = true;
                res1++;
                continue;
            }
            if (i == '1' && beg) {
                if (res1 <= res0)
                    ans = max(ans, res1);
                res1++;
            }

        }
        if (res1 <= res0)
            ans = max(ans, res1);
        return ans * 2;
    }
};

int main() {
    cout << (new Solution)->findTheLongestBalancedSubstring("001");
    return 0;
}