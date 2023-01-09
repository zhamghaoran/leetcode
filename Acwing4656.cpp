#include "bits/stdc++.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    priority_queue<pair<int ,int > > faq;
    int x,y;
    int ans = 0;
    for (int i = 1; i <= a; i++)
        scanf("%d%d", &x, &y),faq.emplace(x,y);
    for (int i = 1;i <= b;i ++) {
        pair<int ,int > item = faq.top();
        faq.pop();
        pair<int ,int > qaq = faq.top();
        if (item.first > qaq.first) {
            while (item.first >= qaq.first && i <= b) {
                ans += item.first;
                item.first -= item.second;
                i ++;
            }
            i --;
        }
        faq.push(item);
    }
    cout<<ans;
    return 0;
}