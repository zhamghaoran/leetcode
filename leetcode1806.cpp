#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> val(n);
        vector<int> qaq(n);
        int ans = 0;
        for (int i = 0;i < n;i ++)
            val[i] = i;
        while (1) {
            ans ++;
            for (int i = 0;i < n;i ++) {
                if (!(i & 1))
                    qaq[i] = val[i / 2];
                else
                    qaq[i] = val[n / 2 + (i - 1) / 2];
            }
            val = qaq;
            bool faq = false;
            for (int i = 1;i < n;i ++) {
                if (val[i] < val[i - 1])
                    faq = true;
            }
            if (!faq) {
                break;
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}