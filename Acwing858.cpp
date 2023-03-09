#include "bits/stdc++.h"
using namespace std;
struct node {
    int f,t,val;
}rt[1000010];
int cnt;
void add(int x,int y,int z) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
}
int fa[1000010];
int fin(int x) {
    return fa[x] == x ? fa[x] : fa[x] = fin(fa[x]);
}
void unin(int x,int y) {
    x = fin(x);
    y = fin(y);
    fa[x] = y;
}
int main() {
    int a,b;
    cin>>a>>b;
    int x,y,z;
    for (int i =1;i <= a;i ++)
        fa[i] = i;
    for (int i = 1;i <= b;i ++) {
        ::scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    sort(rt + 1,rt + 1 + cnt,[&](node a,node b) -> bool  {
        return a.val < b.val;
    });
    int cnt1 = 0;
    long long ans = 0;
    for (int i = 1;i <= cnt;i ++) {
        if (cnt1 >= a)
            break;
        if (fin(rt[i].t) != fin(rt[i].f)) {
            unin(rt[i].f,rt[i].t);
            ans += rt[i].val;
            cnt1 ++;
        }
    }
    if (cnt1 == a - 1)
        cout<< ans;
    else
        cout<<"impossible";
    return 0;
}