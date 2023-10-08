#include "bits/stdc++.h"

using namespace std;

class StockPrice {
public:
    map<int, int> mapp;
    priority_queue<pair<int, int>> maxx;
    priority_queue<pair<int, int>> minn;
    set<pair<int, int>> expire;

    StockPrice() {}

    void update(int timestamp, int price) {
        if (mapp.count(timestamp)) {
            expire.insert(make_pair(mapp[timestamp], timestamp));
        }
        maxx.emplace(price, timestamp);
        minn.emplace(-price, timestamp);
        if (expire.count(make_pair(price, timestamp))) {
            expire.erase(make_pair(price, timestamp));
        }
        mapp[timestamp] = price;
    }

    int current() {
        return mapp.rbegin()->second;
    }

    int maximum() {
        while (!maxx.empty() && expire.count(maxx.top())) {
            maxx.pop();
        }
        return maxx.top().first;
    }

    int minimum() {
        while (!minn.empty()) {
            auto x = minn.top();
            x.first = -x.first;
            if (expire.count(x)) {
                minn.pop();
            } else {
                break;
            }
        }
        return -minn.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
int main() {
    StockPrice *obj = new StockPrice();
    obj->update(1, 4);
    obj->update(1, 5);
    obj->update(1, 4);
    cout << obj->maximum() << endl;
    cout << obj->minimum() << endl;
    cout << obj->current() << endl;
    return 0;
}