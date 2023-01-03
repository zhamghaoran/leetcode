#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int val[200010];
    for (int i = 1;i <= a;i ++) {
        cin>>val[i];
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = a;i >= 2; i -- ){
        sum += val[i];
        ans += val[i - 1] * sum;
    }
    cout<<ans;
    return 0;
}