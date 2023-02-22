#include "bits/stdc++.h"
using namespace std;
int fa[20010];
int fin(int  x) {
    if (fa[x] == x)
        return fa[x];
    return fa[x] = fin(fa[x]);
}
void unin(int x,int y) {
    x = fin(fa[x]);
    y = fin(fa[y]);
    fa[x] = y;
}
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) fa[i]  = i;
    int x,y;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d",&x,&y);
        unin(x,y);
    }
    int z;
    cin>>z;
    for (int i = 1;i  <= z;i ++) {
        scanf("%d%d",&x,&y);
        if (fin(x) == fin(y))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}