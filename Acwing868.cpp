#include "bits/stdc++.h"
using namespace std;
int main() {
    int ans  = 0;
    int a;
    cin>>a;
    vector<int> vis(a + 10,0);
    for (int i = 2;i <= a;i ++) {
        if (!vis[i]) {
            ans ++;
            for (int j = i;(long long)j * (long long)i <= a;j ++)
                vis[i * j] = 1;
        }
    }
    cout<<ans;
    return 0;
}