#include "bits/stdc++.h"

using namespace std;

class SeatManager {
public:
    priority_queue<int> qu;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            qu.push(-i);
        }
    }

    int reserve() {
        int x = qu.top();
        qu.pop();
        return -x;
    }

    void unreserve(int seatNumber) {
        qu.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
int main() {
    return 0;
}