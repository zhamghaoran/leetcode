#include "bits/stdc++.h"
#define int long long
using namespace std;
int ans;
void pd(int x) {
   string qaq = to_string(x);
    vector<int> val;
    while (x) {
        val.push_back(x % 10);
        x /= 10;
    }
    int i = 0,j = val.size() - 1;
    while (i <= j) {
        if (val[i] != val[j])
            return;
        i ++;
        j --;
    }
    if (val[1] < val[0])
        return;
    ans ++;
}
signed main() {
    for (int i = 2022;i <= 100000000;i ++) {
        if (i % 10000000 == 0)
            cout<<i<<endl;
        pd(i);
    }
    cout<<ans;
    return 0;
}