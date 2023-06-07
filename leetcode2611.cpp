#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0;
        vector<pair<int ,int> > faq;
        for (int i = 0;i < reward1.size();i ++) {
            faq.emplace_back(reward1[i] - reward2[i],i);
        }
        std::sort(faq.begin(), faq.end(),[&](pair<int, int> a,pair<int ,int> b) -> bool {
            return a.first > b.first;
        });
        set<int> qaq;
        for (int i = 0;i < k;i ++)
            qaq.insert(faq[i].second);
        for (int i = 0;i < reward1.size();i ++) {
            if (qaq.count(i))
                ans += reward1[i];
            else ans += reward2[i];
        }
        return ans;
    }
};
int main() {
    vector<int> qaq = {4,1,5,3,3};
    vector<int> faq ={3,4,4,5,2};
    cout<<(new Solution)->miceAndCheese(qaq,faq,3);
    return 0;
}