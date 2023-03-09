#include "bits/stdc++.h"
using namespace std;
struct  node {
    int f,t,nex;
}rt[2010];
int head[1010];
int cnt;
int fa[1010];
int son[1010];
int siz[1010];
int dep[1110];
int top[1010];

void add(int x,int y) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

void dfs(int x,int fa1) {
    fa[x] = fa1;
    dep[x] = dep[fa1] + 1;
    siz[x] = 1;
    for(int i = head[x];i;i = rt[i].nex) {
        if(rt[i].t != fa1) {
            dfs(rt[i].t,x);
            siz[x] += siz[rt[i].t];
            if(siz[rt[i].t] > siz[son[x]])
                son[x] = rt[i].t;
        }
    }
}

void dfs2(int x,int topp) {
    top[x] = topp;
    if(son[x])
        dfs2(son[x],topp);
    for(int i = head[x];i;i = rt[i].nex) {
        if(rt[i].t != fa[x] && rt[i].t != son[x])
            dfs2(rt[i].t,rt[i].t);
    }
}

int lca(int x,int y) {
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]])
            swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x,y);
    return x;
}

void solve() {
    cnt = 0;
    int a,b;
    cin>>a>>b;
    int x,y;
    for (int i = 1;i <= a;i ++) {
        scanf("%d%d",&x,&y);
        if(x > 0)
            add(i,x), add(x,i);
        if (y > 0)
            add(i,y),add(y,i);
    }
    dfs(1,0);
    dfs2(1,1);
    for (int i = 1;i <= b;i ++) {
        ::scanf("%d%d",&x,&y);
        ::printf("%d\n",dep[x] + dep[y] - 2 * dep[lca(x,y)]);
    }
}
int main() {
    int t;
    cin>>t;
    while (t --) {
        solve();
    }
    return 0;
}