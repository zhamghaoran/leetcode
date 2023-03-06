#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    vector<int> faq(a + 10);
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&faq[i]);
    }
    stack<int> sta;
    for (int i = 1;i <= a;i ++) {
        if (sta.empty())
            ::printf("%d ",-1),sta.push(faq[i]);
        else {
            while (!sta.empty() && sta.top() >= faq[i]) sta.pop();
            if (sta.empty()) ::printf("%d ",-1);
            else printf("%d ",sta.top());
            sta.push(faq[i]);
        }
    }
    return 0;
}