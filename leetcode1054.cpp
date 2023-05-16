#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct ValueCompare {
        bool operator()(const int &a, const int &b) const {
            return a > b;
        }
    };
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        std::map<int, int, std::function<bool(const int &, const int &)> > faq(
                [](const int &a, const int &b) -> bool {
                    return a > b;
                }
        );
        std::for_each(barcodes.begin(), barcodes.end(), [&](const auto &item) {
            if (!faq.count(item))
                faq[item] = 1;
            else faq[item]++;
        });
        vector<int> ans;
        auto fin = [&](int x) -> int {
            for (auto & it : faq) {
                if (it.first != x) {
                    it.second--;
                    return it.first;
                }
            }
            return 0;
        };
        for (int i = 0; i < barcodes.size(); i++) {
            if (i - 1 < 0)
                ans.push_back(fin(0));
            else
                ans.push_back(fin(ans[i - 1]));
        }
        return ans;
    }
};

int main() {
    vector<int> faq = {2, 2, 2, 1, 5};
    vector<int> ans = (new Solution)->rearrangeBarcodes(faq);
    std::for_each(ans.begin(), ans.end(), [&](const auto &item) {
        cout << item << endl;
    });
    return 0;
}