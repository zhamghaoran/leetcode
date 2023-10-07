#include "bits/stdc++.h"

using namespace std;

class StockSpanner {
public:
    int len = 1;
    vector<int> faq;

    StockSpanner() {
    }

    int next(int price) {
        int ans = 0;
        faq.push_back(price);
        for (int i = faq.size() - 1;i >= 0;i --) {
            if (faq[i] <= price) ans ++;
            else break;
        }
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
    obj->next(80);
    obj->next(60);
    cout << obj->next(70);
    return 0;
}