#include "bits/stdc++.h"
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    vector<pair<pair<int ,int>,int> > val;
    int x,y,z;
    for (int i = 1;i <= a;i ++) {
        scanf("%d%d%d",&x,&y,&z);
        val.emplace_back(make_pair(x,y),z);
    }

    return 0;
}