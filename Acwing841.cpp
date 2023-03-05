#include "bits/stdc++.h"
using namespace std;
#define int unsigned long long
int val[1000010];
int mod = 131;
int cnt[1000010];

int query(int x,int y) {
    return val[y] - val[x - 1] * cnt[y - x + 1];
}

signed main() {
    int a,b;
    cin>>a>>b;
    string c;
    cin>>c;
    cnt[0] = 1;
    val[0] = 0;
    for (int i = 0;i < c.size();i ++) {
        cnt[i + 1]  = cnt[i] * mod;
        val[i + 1] = val[i] * mod + c[i] - 'a' + 1;
    }
    int x,y,xx,yy;
    for (int i = 1;i <= b;i ++) {
        cin>>x>>y>>xx>>yy;
        if (query(x, y) == query(xx, yy))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}