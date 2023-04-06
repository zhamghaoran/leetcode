#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string baseNeg2(int n) {
        vector<int> qaq;
        while (n) {
            qaq.push_back(n & 1);
            n >>= 1;
        }
        int add = 0;
        for (int i = 0;i < qaq.size();i ++) {
            qaq[i] += add;
            add = qaq[i] / 2;
            qaq[i] %= 2;
            if (i & 1) {
                add += qaq[i];
            }
        }
        if (add) {
            qaq.push_back(1);
            if (!(qaq.size() & 1))
                qaq.push_back(1);
        }
        if (qaq.empty())
            return "0";
        string ans;
        std::reverse(qaq.begin(), qaq.end());
        std::for_each(qaq.begin(), qaq.end(), [&](const auto &item) {
            ans.push_back(item + '0');
        });
        return ans;
    }
};
int main() {
    cout<<(new Solution)->baseNeg2(6);
    return 0;
}