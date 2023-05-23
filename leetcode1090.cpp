#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        vector<pair<int, int> > faq;
        for (int i = 0; i < values.size(); i++)
            faq.emplace_back(values[i], labels[i]);
        std::sort(faq.begin(), faq.end(), [&](const pair<int, int> a, const pair<int, int> b) -> bool {
            return a.first > b.first;
        });
        int ans = 0;
        map<int, int> mapp;
        int cnt = 0;
        for (auto & i : faq) {
            if (mapp[i.second] < useLimit) {
                mapp[i.second]++;
                cnt++;
                ans += i.first;
            }

            if (cnt == numWanted)
                break;
        }

        return ans;
    }
};

int main() {
    return 0;
}