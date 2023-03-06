#include "bits/stdc++.h"
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    vector<int> val(a + 10);
    for (int i = 1;i <= a;i ++) {
        cin>>val[i];
    }
    deque<int> queue;
    for (int i = 1;i <= b;i ++) {
        if (queue.empty())
            queue.push_front(i);
        else {
            while (!queue.empty() && val[i] < val[queue.back()])
                queue.pop_back();
            queue.push_back(i);
        }
    }
    for (int i = b;i <= a;i ++) {
        while (!queue.empty() && val[i] < val[queue.back()])
            queue.pop_back();
        queue.push_back(i);
        ::printf("%d ",val[queue.front()]);
        while (!queue.empty() && i - queue.front() + 1 >= b)
            queue.pop_front();
    }
    queue.clear();
    ::puts("");
    for (int i = 1;i <= b;i ++) {
        if (queue.empty())
            queue.push_front(i);
        while (!queue.empty() && val[i] > val[queue.back()])
            queue.pop_back();
        queue.push_back(i);
    }
    for (int i = b;i <= a;i ++) {
        while (!queue.empty() && val[i] > val[queue.back()])
            queue.pop_back();
        queue.push_back(i);
        ::printf("%d ",val[queue.front()]);
        while (!queue.empty() && i - queue.front() + 1 >= b)
            queue.pop_front();
    }
    return 0;
}