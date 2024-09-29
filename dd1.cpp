#include "bits/stdc++.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    unordered_set<int> val;
    int x;
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&x);
        val.emplace(x);
    }
    int now = 0;
    int cnt = 0;
    for (int i = 1;i <= b;i ++) {
        if (!val.count(i)) {
            now += i;
            cnt ++;
        }
        if (now > b) {
            break;
        }
    }
    cout<<cnt - 1;
    return 0;
}