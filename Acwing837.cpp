#include "bits/stdc++.h"
using namespace std;
int fa[1000010];
int siz[1000010];
int fin(int x) {
    if (fa[x] == x)
        return fa[x];
    else
        return fa[x] = fin(fa[x]);
}
void unin(int x,int y) {
    x = fin(x);
    y = fin(y);
    fa[y] = x;
    if (x != y)
        siz[x] += siz[y];
}
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++)
        fa[i] = i,siz[i] = 1;
    for (int i = 1;i <= b;i ++) {
        string x;
        cin>>x;
        int xx,yy;
        if (x == "C") {
            cin>>xx>>yy;
            unin(xx,yy);
        } else if ( x == "Q1") {
            cin>>xx>>yy;
            if (fin(xx) == fin(yy)) {
                cout<<"Yes\n";
            } else
                cout<<"No\n";
        } else {
            cin>>xx;
            cout<<siz[fin(xx)]<<endl;
        }
    }
    return 0;
}