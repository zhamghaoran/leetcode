#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ways(vector<string> &pizza, int k) {
        int mod = 1e9 + 7;
        int a = pizza.size();
        int b = pizza[0].size();
        vector<vector<int>> apples(a + 1, vector<int>(b + 1));
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(a + 1, vector<int>(b + 1)));

        for (int i = a - 1; i >= 0; i--) {
            for (int j = b - 1; j >= 0; j--) {
                apples[i][j] = apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
                dp[1][i][j] = apples[i][j] > 0;
            }
        }
        for (int ki = 2; ki <= k; ki++) {
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {

                    for (int ii = i + 1; ii < a; ii++) {
                        if (apples[i][j] > apples[ii][j]) {
                            dp[ki][i][j] += dp[ki - 1][ii][j];
                            dp[ki][i][j] %= mod;
                        }
                    }

                    for (int jj = j + 1; jj < b; jj++) {
                        if (apples[i][j] > apples[i][jj]) {
                            dp[ki][i][j] += dp[ki - 1][i][jj];
                            dp[ki][i][j] %= mod;
                        }
                    }
                }
            }
        }
        return dp[k][0][0] % mod;
    }
};

int main() {
    vector<string> faq = {"A..","A..","..."};
    (new Solution)->ways(faq,3);
    return 0;
}