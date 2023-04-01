#include "bits/stdc++.h"
using namespace std;
struct node {
    int f,t,nex;
}rt[100010];
int head[100010];
int cnt;
int dp[100010];
void add(int x,int y) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
void dfs(int x) {
    int n = 0;
    int maxx = 0;
    for (int i = head[x];i;i = rt[i].nex) {
        n ++;
        dfs(rt[i].t);
        maxx = max(maxx,dp[rt[i].t]);
    }
    dp[x] = maxx + n;
}
int main() {
    int a;
    cin>>a;
    int x;
    for (int i = 2;i <= a;i ++) {
        cin>>x;
        add(x,i);
    }
    dfs(1);
    cout<<dp[1];
    return 0;
}