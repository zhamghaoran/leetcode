#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int ans = 0;
        int minn1 = 0;
        int minn2 = -prices[0] - fee;
        for (int i = 1; i < prices.size(); i++) {
            minn1 = max(minn1,minn2 + prices[i]);
            minn2 = max(minn2,minn1 - prices[i] - fee);
            ans = max(ans,minn1);
        }
        return ans;
    }
};

int main() {

    return 0;
}