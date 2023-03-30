#include "bits/stdc++.h"
#define int unsigned long long
using namespace std;
signed main() {
    int a;
    cin>>a;
    int cnt = 1;
    int now = 1;
    vector<int> val;
    val.push_back(0);
    while (true) {
        if (now == 1) {
            val.push_back(1);
            if (now == cnt)
                cnt ++,now = 0;
            now ++;
            continue;
        }
        if (cnt == now) {
            val.push_back(1);
            cnt ++;
            now = 0;
        } else {
            int num = (1 + cnt - 2) * (cnt - 2) / 2 + now - 1;
            if (val[num] + val[num + 1] == a) {
                cout<<(1 + cnt - 1) * (cnt - 1) / 2 + now;
               return 0;
            }
            val.push_back(val[num] + val[num + 1]);
        }
        now ++;
    }

}