#include "bits/stdc++.h"
#define INF 0x7f7f7f7f
using namespace std;
struct node {
    int f,t,nex,val;
}rt[100010];
int head[100010];
int cnt;
int s,t;
int vis[100010];
int cur[100010];
void add(int x,int y) {

    rt[cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = 1;
    rt[cnt].nex = head[x] ;
    head[x] = cnt ++;
    rt[cnt].f = y;
    rt[cnt].t = x;
    rt[cnt].val = 0;
    rt[cnt].nex = head[y];
    head[y] = cnt ++;

}
int a,b;
int find(int x,int lim) {
    if (x == t)
        return lim;
    int flow = 0;
    for (int i = cur[x];~i;i = rt[i].nex) {
        cur[x] = i;
        if (vis[rt[i].t] == vis[x] + 1 && rt[i].val) {
            int ans = find(rt[i].t, min(rt[i].val,lim - flow));
            if (!ans)
                vis[rt[i].t] = -1;
            rt[i].val -= ans;
            rt[i ^ 1].val += ans;
            flow += ans;
        }
    }
    return flow;
}
bool bfs() {
    queue<int> p;
    ::memset(vis,-1,sizeof vis);
    cur[s] = head[s];
    vis[s] = 0;
    p.push(s);
    while (!p.empty()) {
        int faq = p.front();
        p.pop();
        for (int i = head[faq];~i;i = rt[i].nex) {
            if (vis[rt[i].t] == -1 && rt[i].val) {
                vis[rt[i].t] = vis[faq] + 1;
                cur[rt[i].t] = head[rt[i].t];
                if (rt[i].t == t)
                    return true;
                p.push(rt[i].t);
            }
        }
    }
    return false;
}
int dinic() {
    int flow = 0;
    int ans;
    while (bfs()) {
        while ((ans = find(s,INF)))
            flow += ans;
    }
    return flow;
}
int main() {
    ::memset(head,-1,sizeof head);
    cin>>a>>b;
    s = 0;
    t = a + b + 1;
    int x,y;
    for (int i = 1;i <= a;i ++) {
        cin>>x;
        for (int j = 1;j <= x;j ++) {
            cin>>y;
            add(i,y + a);
        }
    }
    for (int i = 1;i <= a;i ++) {
        add(0,i);
    }
    for (int i = a + 1;i <= a + b;i ++)
        add(i,a + b + 1);
    cout<<dinic();
    return 0;
}