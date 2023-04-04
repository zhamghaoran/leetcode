#include "bits/stdc++.h"
#define int long long
using namespace std;
signed main() {
    int a,b;
    cin>>a>>b;
    int cha = abs(a - b);
    cout<<(a % cha == 0 ? 0 : cha - a % cha);
    return 0;

}