#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &nums) {
        vector<int> dp(1 << nums.size(), 0);
        int gcd[100][100];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);
            }
        }
        for (int i = 1; i <= 1 << nums.size(); i++) {
            int p = __builtin_popcount(i);
            if (p & 1)
                continue;
            for (int x = 0; x < nums.size(); x++) {
                if (i >> x & 1) {
                    for (int y = x + 1; y < nums.size(); y++) {
                        if (i >> y & 1) {
                            dp[i] = max(dp[i], dp[i ^ (1 << x) ^ (1 << y)] + p / 2 * gcd[x][y]);
                        }
                    }
                }
            }
        }
        return dp[(1 << nums.size()) - 1];
    }
};

int main() {

    return 0;
}