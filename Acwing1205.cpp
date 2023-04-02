#include "bits/stdc++.h"
using namespace std;
bool qaq[10000010];
int main() {
    int a,b;
    cin>>a>>b;
    int maxx = 1;
    qaq[a] = 1;
    qaq[b] = 1;
    for (int i = min(a,b);i <= 10000000;i ++) {
        if(!qaq[i])
            maxx = i;
        else qaq[i + a] = 1,qaq[i + b] = 1;
    }
    cout<<maxx;
    return 0;
}