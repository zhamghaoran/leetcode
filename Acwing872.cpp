#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    int x,y;
    for (int i = 1;i <= a;i ++)
        cin>>x>>y,cout<<__gcd(x,y)<<endl;
    return 0;

}