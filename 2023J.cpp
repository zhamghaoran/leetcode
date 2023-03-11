#include "bits/stdc++.h"
using namespace std;
struct node {
    int f,t,nex;
}rt[1000100];
int head[100010];
int cnt;
int dis[100010];
int dis1[1000010];
void add(int x,int y) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y;
    for (int i = 1;i <= b;i ++) {
        ::scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    int ans = 0;
    vector<int> des;
    priority_queue<pair<int ,int> > faq;
    ::memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    faq.emplace(0,1);
    while (!faq.empty()) {
        auto qaq = faq.top();
        faq.pop();
        for (int i = head[qaq.second];i;i = rt[i].nex) {
            if (dis[rt[i].t] > dis[qaq.second] + 1) {
                dis[rt[i].t] = dis[qaq.second] + 1;
                if (dis[rt[i].t] <= c) {
                    faq.emplace(-dis[rt[i].t],rt[i].t);
                }
            }
        }
    }
    for (int i = 1;i <= a;i ++)
        if (dis[i] <= c)
            ::printf("%d ",i);
    ::puts("");
    ::memset(dis1,0x3f,sizeof dis1);
    dis1[a] = 0;
    faq.emplace(0,a);
    while (!faq.empty()) {
        auto qaq = faq.top();
        faq.pop();
        for (int i = head[qaq.second];i;i = rt[i].nex) {
            if (dis1[rt[i].t] > dis1[qaq.second] + 1) {
                dis1[rt[i].t] = dis1[qaq.second] + 1;
                if (dis1[rt[i].t] <= d) {
                    faq.emplace(-dis1[rt[i].t],rt[i].t);
                }
            }
        }
    }
    bool faqq = false;
    for (int i = 1;i <= a;i ++) {
        if (dis1[i] <= d)
            ::printf("%d ",i);
        if (dis[i] <=c && dis1[i] <= d)
            faqq = true;
    }
    ::puts("");
    if (faqq)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}