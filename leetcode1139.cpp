#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int mapp[1010][1010];
    int dp[1010][1010];
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int a = grid.size();
        int b = grid[0].size();
        int ans = 0;
        for (int i = 1;i <= a;i ++) {
            for (int j = 1;j <= b;j ++) {
                mapp[i][j] = grid[i - 1][j - 1];
                if (mapp[i][j]) dp[i][j] = 1;
            }
        }
        for (int i = 1;i <= a;i ++) {
            for (int j = 1;j <= b;j ++) {
                if (dp[i][j]) {
                    ans = max(ans,dp[i][j]);
                    int cnt = 1;
                    int x = dp[i][j];
                    while (i + cnt <= a && j + cnt <= b) {
                        if (dp[i + cnt][j + cnt]) {
                            bool faq = true;
                            for (int xx = 1;xx <= cnt + x;xx ++) {
                                if (!mapp[i + cnt][j - x + xx] ) faq = false;
                                if (!mapp[i - x + xx][j + cnt]) faq = false;
                            }
                            for (int xx = 1;xx <= cnt;xx ++) {
                                if (!mapp[i + xx][j - x + 1]) faq = false;
                                if (!mapp[i - x + 1][j + xx]) faq = false;
                            }
                            if (faq) {
                                dp[i + cnt][j + cnt] = dp[i][j] + cnt;
                                ans = max(ans,dp[i + cnt][j + cnt]);
                                break;
                            }
                        }
                        cnt ++;
                    }
                }
            }
        }
        return ans * ans;
    }
};
int main() {
    vector<vector<int>> faq = {{1,1,1,1,1,1},{1,0,1,0,1,1},{1,1,1,0,1,1},{1,1,1,1,1,1},{1,1,1,1,1,0}};
    cout<<(new Solution)->largest1BorderedSquare(faq);
    return 0;
}