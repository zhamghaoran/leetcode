#include "bits/stdc++.h"
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int x,y;
    map<int ,int > mapp;
    int ans = 0;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d",&x,&y);
        if (y == 0) {
            mapp[x] = 1;
            continue;
        }
        if (!mapp[y])
            ans ++;
        mapp[x] = 1;
    }
    cout<<ans;
    return 0;
}