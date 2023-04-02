#include "bits/stdc++.h"
#define int long long
using namespace std;
struct node {
    int f,t,val,nex;
}rt[400010];
int head[100010];
int cnt;
void add(int x,int y,int z) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int maxx;
int sum;
void dfs(int x,int f,int ss) {
    for (int i = head[x];i;i = rt[i].nex) {
        if (rt[i].t != f) {
            if (ss + rt[i].val > sum) {
                maxx = rt[i].t;
                sum = ss + rt[i].val;
            }
            dfs(rt[i].t,x,ss + rt[i].val);
        }
    }
}
signed main() {
    int a;
    cin>>a;
    int x,y,z;
    for (int i  = 1;i < a;i ++) {
        ::scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0,0);
    sum = 0;
    dfs(maxx,0,0);
    cout<<(11 + 10 + sum) * sum / 2;
    return 0;
}