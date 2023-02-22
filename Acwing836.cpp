#include "bits/stdc++.h"
using namespace std;
int fa[100010];
int fin(int x) {
    if (fa[x] == x)
        return fa[x];
    return fa[x] = fin(fa[x]);
}
void unin(int x,int y) {
    x = fin(x);
    y = fin(y);
    fa[x] = y;
}
int main()  {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) fa[i] = i;
    char c;
    int x,y;
    for (int i= 1;i <= b;i ++) {
        cin>>c;
        cin>>x>>y;
        if (c == 'M'){
            unin(x,y);
        } else {
            cout<<(fin(x) == fin(y) ? "Yes" : "No");
            ::puts("");
        }
    }
    return 0;
}