#include "bits/stdc++.h"
using namespace std;
int zhi[100010];
int cnt;
int vis[1000010];

void init() {
    for (int i = 2;i <= 10000;i ++) {
        if (!vis[i]) {
            zhi[++ cnt] = i;
            for (int j = i;i * j <= 10000;j ++) {
                vis[i * j] = 1;
            }
        }
    }
}

bool pd(int x,int y) {
    int ans = 0;
    for (int i = 2;zhi[i] <= x ;i ++) {
        int end = lower_bound(zhi + 1,zhi + 1 + cnt,zhi[i] + zhi[i - 1]  + 1) - zhi;
        if (zhi[end] == zhi[i] + zhi[i - 1] + 1 && zhi[end] <= x)
            ans ++;
    }
    return ans >= y;
}

int main() {
    init();
    int x;
    cin>>x;
    int a,b;
    while (x --) {
        cin>>a>>b;
        pd(a,b) ? cout<<"YES\n" : cout<<"NO\n";
    }
    return 0;
}