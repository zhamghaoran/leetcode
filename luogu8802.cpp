#include "bits/stdc++.h"
using namespace std;
struct node {
    int f,t,val,nex;
}rt[100001];
int head[100010];
int cnt;
void add(int x,int y,int z) {
    rt[++ cnt].f = x;
    rt[cnt].val = z;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] =  cnt;
}
int val[1000010];
int vis[1000100];
int ans[1000010];
int main() {
    int a,b;
    cin>>a>>b;
    for(int i =1 ;i <= a;i ++) {
        scanf("%d",&val[i]);
    }
    int x,y,z;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    memset(ans,0x3f,sizeof ans);
    ans[1] = 0;
    priority_queue<pair<int, int> > faq;
    faq.emplace(0,1);
    while (!faq.empty()) {
        auto xx = faq.top();
        faq.pop();
        if (vis[xx.second])
            continue;
        vis[xx.second] = 1;
        for(int i = head[xx.second]; i; i = rt[i].nex) {
            if (ans[rt[i].t] > ans[xx.second] + rt[i].val + val[rt[i].t]) {
                ans[rt[i].t] = ans[xx.second] + rt[i].val + val[rt[i].t];
                faq.emplace(-ans[rt[i].t],rt[i].t);
            }
        }
    }
    cout<<ans[a] - val[a];
    return 0;
}