#include "bits/stdc++.h"
using namespace std;
int val[100010];
int cha[100010];
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i ++) {
        cin>>val[i];
    }
    for (int i = 1;i <= b;i ++) {
        int l,r,x;
        cin>>l>>r>>x;
        cha[l - 1] += x;
        cha[r] -= x;
    }
    int sum = cha[0];
    for (int i = 1;i <= a;i ++) {
        val[i] += sum;
        sum += cha[i];
        cout<<val[i]<<" ";
    }
    return 0;
}