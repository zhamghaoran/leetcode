#include "bits/stdc++.h"
using namespace std;
int a;
int vis[10];
int ans[10];
void dfs(int num) {
    if (num >= a) {
        for (int i = 0;i < a;i ++) {
            cout<<ans[i]<<" ";
        }
        puts("");
        return;
    }
    for (int i = 1;i <= a;i ++) {
        if (!vis[i]) {
            ans[num] = i;
            vis[i] = 1;
            dfs(num + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    cin>>a;
    dfs(0);
}