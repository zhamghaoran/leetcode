#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> val;
        vector<int> qaq;
        if (x == 1)
            val.push_back(1);
        else {
            int sum = 1;
            for (;;) {
                val.push_back(sum);
                sum *= x;
                if (sum > bound) {
                    break;
                }
            }
        }
        if (y == 1)
            qaq.push_back(1);
        else {
            int sum = 1;
            for (;;) {
                qaq.push_back(sum);
                sum *= y;
                if (sum > bound)
                    break;
            }
        }
        set<int> ans;
        std::for_each(val.begin(), val.end(), [&](const int item) {
            int cnt = std::upper_bound(qaq.begin(), qaq.end(),bound - item) - qaq.begin();
            if (cnt > 0) {
                for (int i = 0;i <  cnt;i ++) {
                    ans.insert(item + qaq[i]);
                }
            }
        });
        vector<int> faq;
        std::for_each(ans.begin(), ans.end(), [&](const auto &item) {
            faq.push_back(item);
        });
        return faq;
    }
};

int main() {

    vector<int> ans = (new Solution)->powerfulIntegers(2,3,10);
    std::sort(ans.begin(), ans.end());
    std::for_each(ans.begin(), ans.end(), [&](const int &item) {
        cout<<item<<endl;
    });
    return 0;
}