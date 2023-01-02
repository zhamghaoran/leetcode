#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        priority_queue<pair<long long, long long> > buy;
        priority_queue<pair<long long, long long> > sell;
        for (auto &i: orders) {
            if (i[2] == 1) {
                while (!buy.empty() && i[0] <= buy.top().first) {
                    pair<long long, long long> item = buy.top();
                    if (item.second < i[1])
                        i[1] -= item.second, buy.pop();
                    else {
                        item.second -= i[1];
                        i[1] = 0;
                        buy.pop();
                        buy.push(item);
                        break;
                    }
                }
                if (i[1] > 0)
                    sell.emplace(-i[0], i[1]);
            } else {
                while (!sell.empty() && i[0] >= abs(sell.top().first)) {
                    pair<long long, long long> item = sell.top();
                    if (item.second < i[1])
                        i[1] -= item.second, sell.pop();
                    else {
                        item.second -= i[1];
                        i[1] = 0;
                        sell.pop();
                        sell.push(item);
                        break;
                    }
                }
                if (i[1] > 0)
                    buy.emplace(i[0], i[1]);
            }
        }
        long long ans = 0;
        while (!buy.empty()) { ans += buy.top().second, ans %= mod, buy.pop(); }
        while (!sell.empty()) { ans += sell.top().second, ans %= mod, sell.pop(); }
        return int(ans % mod);
    }
};

int main() {
    vector<vector<int>> faq = {{7,  1000000000, 1},
                               {15, 3,          0},
                               {5,  999999995,  0},
                               {5,  1,          1}};
    cout << (new Solution)->getNumberOfBacklogOrders(faq);
    return 0;
}