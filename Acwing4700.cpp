#include "bits/stdc++.h"
using namespace std;
int val[100];
int faq[10000010];
int main() {
    int a,b;
    cin>>a>>b;
    int sum = 0;
    for(int i = 1;i <= a;i ++) {
        cin>>val[i];
        sum += val[i];
    }
    faq[0] = 1;
    for (int i = 0;i <= a;i ++) {
        for (int j = sum;j >= val[i];j --) {
            faq[j] |= faq[j - val[i]];
        }
    }
    for (int i = b;i <= sum;i ++) {
        if (faq[i]) {
            cout<<i;
            return 0;
        }
    }
    cout<<sum;
    return 0;
}