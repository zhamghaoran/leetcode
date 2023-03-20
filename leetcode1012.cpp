#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<bool> vis(n * 2, false);
        int ans = 0;
        auto operation = [&](int x) {
            int qaq = x;
            vector<int> val;
            while (qaq) {
                val.push_back(qaq % 10);
                qaq /= 10;
            }
            std::for_each(val.begin(), val.end(), [&](const auto &item) {
                int now = x;
                while (now * 10 <= n) {
                    vis[now * 10 + item] = 1;
                    now *= 10;
                }
            });
        };
        for (int i = 1; i <= n; i ++)
            if (!vis[i])
                operation(i),ans ++;
        return n - ans;
    }
};

int main() {
    cout<<(new Solution)->numDupDigitsAtMostN(1000000000);
    return 0;
}