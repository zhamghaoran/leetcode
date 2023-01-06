#include "bits/stdc++.h"
using namespace std;
int main() {
    char a;
    int b;
    cin>>a>>b;
    int l = 1189;
    int r = 841;
    int x;
    for (int i = 1;i <= b;i ++) {
        x = l / 2;
        l = r;
        r = x;
    }
    cout<<l<<endl<<r;
    return 0;
}