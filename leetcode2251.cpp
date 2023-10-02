#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        vector<int> ans;
        vector<int> faq;
        map<int, int> chafen;
        std::for_each(flowers.begin(), flowers.end(), [&](auto a) -> void {
            faq.push_back(a[0]);
            faq.push_back(a[1] + 1);
            chafen[a[0]]++;
            chafen[a[1] + 1]--;
        });
        map<int, int> sum;
        int qaq = 0;
        for (auto i = chafen.begin(); i != chafen.end(); i++) {
            qaq += i->second;
            sum[i->first] = qaq;
        }
        std::sort(faq.begin(), faq.end());
        for (int person: persons) {
            int x = upper_bound(faq.begin(), faq.end(), person) - faq.begin() - 1;
            if (x < 0) {
                ans.push_back(0);
            } else {
                ans.push_back(sum[faq[x]]);
            }
        }
        return ans;
    }
};


int main() {
    vector<vector<int>> faq = {{19, 37},
                               {19, 38},
                               {19, 35}};
    vector<int> qaq = {6, 7, 21, 1, 13, 37, 5, 37, 46, 43};
    vector<int> ans = (new Solution)->fullBloomFlowers(faq, qaq);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}