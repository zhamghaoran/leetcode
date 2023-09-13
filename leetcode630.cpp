#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> dp;

    int scheduleCourse(vector<vector<int>> &courses) {
        dp = vector<int>(10000, 0);
        int ans = 0;
        for (int i = 0; i < courses.size(); i++) {
            for (int j = 20; j >= 0; j--) {
                if (j <= courses[i][1] && j - courses[i][0] >= 0) {
                    dp[j] = max(dp[j - courses[i][0]] + 1, dp[j]);
                }
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{2, 5},
                               {2, 19},
                               {1, 8},
                               {1, 3}};
    cout << (new Solution)->scheduleCourse(faq);
    return 0;
}