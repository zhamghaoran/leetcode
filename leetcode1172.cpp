#include "bits/stdc++.h"

using namespace std;

class DinnerPlates {
    int capacity; // 栈的容量
    vector<stack<int>> stacks; // 所有栈
    priority_queue<int, vector<int>, greater<>> idx; // 未满栈的下标
public:
    DinnerPlates(int capacity) : capacity(capacity) {}

    void push(int val) {

        if (!idx.empty() && idx.top() >= stacks.size())
            while (!idx.empty()) idx.pop(); // 堆中都是越界下标，直接清空
        if (idx.empty()) { // 所有栈都是满的
            stack<int> st;
            st.push(val);
            stacks.emplace_back(st); // 添加一个新的栈
            if (capacity > 1) // 新的栈没有满
                idx.push(stacks.size() - 1); // 入堆
        } else { // 还有未满栈
            auto &st = stacks[idx.top()];
            st.push(val); // 入栈
            if (st.size() == capacity) // 栈满了
                idx.pop(); // 从堆中去掉
        }
    }

    int pop() {
        // 等价为 popAtStack 最后一个非空栈
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1; // 非法操作
        auto &st = stacks[index];
        if (st.size() == capacity) // 满栈
            idx.push(index); // 元素出栈后，栈就不满了，把下标入堆
        int val = st.top();
        st.pop();
        while (!stacks.empty() && stacks.back().empty())
            stacks.pop_back(); // 去掉末尾的空栈（懒删除，堆中下标在 push 时处理）
        return val;
    }
};


/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
int main() {

    return 0;
}