#include "bits/stdc++.h"

using namespace std;


class Solution {
public:

    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() == 1 || nums.size() == 2) {
            return nums.size();
        }
        vector<vector<int>> dp(10010, vector<int>(2, 1));
        if (nums[1] > nums[0]) {
            dp[1][1] = 2;
        } else if (nums[1] < nums[0]) {
            dp[1][0] = 2;
        }
        for (int i = 2; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i][1] = max(dp[j][0] + 1, dp[i][1]);
                } else if (nums[i] < nums[j]) {
                    dp[i][0] = max(dp[j][1] + 1, dp[i][0]);
                }
            }
        }
        return max(dp[nums.size() - 1][1], dp[nums.size() - 1][0]);
    }

};


//[[1,3,1],[1,5,1],[4,2,1]]
//[1,7,4,9,2,5]
int main() {
    vector<int> faq = {1,17,5,10,13,15,10,5,16,8};
    cout << (new Solution)->wiggleMaxLength(faq);
    return 0;
}