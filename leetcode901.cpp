#include "bits/stdc++.h"

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> faq;
    int cnt = 0;

    StockSpanner() {
        faq.emplace(0, 0x3f3f3f3f);
    }

    int next(int price) {
        cnt++;
        while (!faq.empty() && price >= faq.top().second) {
            faq.pop();
        }
        int ans = cnt - faq.top().first;
        faq.emplace(cnt,price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() {
    StockSpanner *obj = new StockSpanner();
    obj->next(100);
    cout<<obj->next(80);
    obj->next(60);
    obj->next(70);
    return 0;
}