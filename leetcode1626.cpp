#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int ans = 0;
        vector<pair<int, int>> faq;
        for (int i = 0; i < scores.size(); i++)
            faq.emplace_back(scores[i], ages[i]);
        std::sort(faq.begin(), faq.end(), [&](pair<int, int> x, pair<int, int> y) -> bool {
            if (x.second == y.second)
                return x.first < y.first;
            return x.second < y.second;
        });
        vector<int> dp(scores.size() + 10, 0);
        dp[0] = faq[0].first;
        for (int i = 1; i < faq.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (faq[j].first <= faq[i].first)
                    dp[i] = max(dp[j] + faq[i].first, dp[i]);
            }
            dp[i] = max(dp[i], faq[i].first);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> score = {9,2,8,8,2};
    vector<int> age = {4,1,3,3,5};
    cout << (new Solution)->bestTeamScore(score, age);
    return 0;
}