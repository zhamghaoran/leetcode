#include "bits/stdc++.h"
using namespace std;
int a,b;
struct node {
    int f,t,nex,val;
}rt[1000010];
int head[300010];
int cnt;
int ans[100010];
int vis[200010];
void add(int x,int y,int z) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int main() {
    cin>>a>>b;
    int x,y,z;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    cin>>x;
    ::memset(ans,0x7f,sizeof ans);
    priority_queue<pair<int ,int>> faq;
    for (int i = 1;i <= x;i ++) {
        scanf("%d",&y);
        ans[y] = 0;
        faq.emplace(0,y);
    }
    while (!faq.empty()) {
        auto qaq = faq.top();
        faq.pop();
        for (int i = head[qaq.second];i;i = rt[i].nex){
            if (ans[rt[i].t] > ans[qaq.second] + rt[i].val){
                ans[rt[i].t] = ans[qaq.second] + rt[i].val;
                faq.emplace(-ans[rt[i].t],rt[i].t);
            }
        }
    }
    cin>>x;
    for (int i = 1;i <= x;i ++) {
        ::scanf("%d",&y);
        ::printf("%d\n",ans[y]);
    }
    return 0;
}