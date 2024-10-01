#include "bits/stdc++.h"

using namespace std;

class MinStack {
public:
    stack<int> st;
    map<int, int> mp;

    MinStack() {

    }
    void push(int val) {
        mp[val] += 1;
        st.push(val);
    }

    void pop() {
        int x = st.top();
        mp[x] -= 1;
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        for (auto [k, v]: mp) {
            if (v > 0) {
                return k;
            }
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {

    return 0;
}