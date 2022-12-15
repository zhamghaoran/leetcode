#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        vector<long long> w(n + 1);
        vector<int> neg(n + 1);
        vector<int> dp(n + 1);
        for (int i = 1;i <= n;i ++) {
            w[i] = boxes[i - 1][1] + w[i - 1];
            if (i > 1)
                neg[i] = neg[i - 1] + (boxes[i - 2][0] != boxes[i - 1][0]);
        }
        deque<int> opt = {0};
        vector<int> g(n + 1);
        for (int i = 1;i <= n;i ++) {
            while (w[i] - w[opt.front()] > maxWeight || i - opt.front() > maxBoxes) {
                opt.pop_front();
            }
            dp[i] = g[opt.front()] + neg[i] + 2;
            if (i != n) {
                g[i] = dp[i] - neg[i + 1];
                while (!opt.empty() && g[i] <= g[opt.back()]) {
                    opt.pop_back();
                }
                opt.push_back(i);
            }
        }
        return dp[n];
    }
};
int main() {
    vector<vector<int>> faq = {{2, 4},
                               {2, 5},
                               {3, 1},
                               {3, 2},
                               {3, 7},
                               {3, 1},
                               {4, 4},
                               {1, 3},
                               {5, 2}};
    cout << (new Solution)->boxDelivering(faq, 5, 5, 7);
    return 0;
}