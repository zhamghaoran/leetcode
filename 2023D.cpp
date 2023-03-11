#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vis(11,0);
int ans;
int a;
void dfs(int x,int num) {
    if (x >= 10) {
        if (num % a == 0)
            ans ++;
    }
    else {
        for (int i = 0;i <= 9;i ++) {
            if (!vis[i]) {
                vis[i] = 1;
                dfs(x + 1,num * 10 + i);
                vis[i] = 0;
            }
        }
    }
}
signed main() {
    cin>>a;
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    do{
        int qaq = 0;
        if (v[9] == 0)
            continue;
       for (int i = v.size() - 1;i >= 0;i -- ) {
           qaq = qaq * 10 + v[i];
       }
       if (qaq % a == 0)
           ans ++;
    }while(next_permutation(v.begin(),v.end()));//获取下一个排列
    cout<<ans;
    return 0;
}