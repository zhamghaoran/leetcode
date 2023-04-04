#include "bits/stdc++.h"
using namespace std;
int xx[1000010];
int yy[1000010];
int rr[1000010];
int vis[1000010];
bool check(int x,int y,int r,int i) {
    if (sqrt((x - xx[i]) * (x - xx[i]) + (y - yy[i]) * (y - yy[i])) <= r) {
        vis[i] = 1;
        return true;
    }
    return false;
}
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) {
        scanf("%d%d%d",&xx[i],&yy[i],&rr[i]);
    }
    int x,y,r;
    int ans = 0;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d%d",&x,&y,&r);
        for (int j = 1;j <= a;j ++) {
            if (vis[j])
                continue;
            if (check(x,y,r,i))
                ans ++;
        }
    }
    printf("%d\n",ans);
    return 0;
}