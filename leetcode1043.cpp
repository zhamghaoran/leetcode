#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int a = arr.size() - 1;
        vector<int> dp(a + 10);
        for (int i = 1; i <= a + 1; i++) {
            int maxx = arr[i - 1];
            for (int j = i - 1;j >= max(i - k,0);j --) {
                dp[i] = max(dp[j] + maxx * (i -  j),dp[i]);
                if (j > 0)
                    maxx = max(maxx,arr[j - 1]);
            }
        }
        return dp[a + 1];
    }
};

int main() {

    return 0;
}