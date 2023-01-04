#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
}rt[1000010];
int main() {
    int a;
    vector<pair<int , int> > val;
    cin>>a;
    for (int i = 1;i <= a;i ++) {
        int first = i;
        int second = 0;
        int x = i;
        while (x) {
            second += x % 10;
            x /= 10;
        }
        rt[i].x = first;
        rt[i].y = second;
    }
    sort(rt + 1,rt + 1 + a,[&](const node  a,const node b) -> bool {
        return a.y == b.y ? a.x < b.x : a.y < b.y;
    });
    int b;
    cin>>b;
    cout<<rt[b].x;
    return 0;
}