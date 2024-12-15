#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        vector<int> dp(4010, 0);
        std::sort(rewardValues.begin(), rewardValues.end());
        dp[rewardValues[0]] = 1;
        for (int i = 1; i < rewardValues.size(); i++) {
            dp[rewardValues[i]] = 1;
            for (int j = 3999; j >= 0; j--) {
                if (j - rewardValues[i] >= 0 && j - rewardValues[i] < rewardValues[i]) {
                    dp[j] = max(dp[j], dp[j - rewardValues[i]]);
                }
            }
        }
        for (int i = 3999; i >= 0; i--) {
            if (dp[i])
                return i;
        }
        return 0;
    }
};

int main() {
    return 0;
}