#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    int x;
    char z;
    vector<int> val;
    while (scanf("%d",&x) != EOF){
        val.push_back(x);
    }
    sort(val.begin(),val.end());
    int m,n;
    for (int i = 1;i < val.size();i ++) {
        if (val[i] == val[i - 1]) {
            m = val[i];
            continue;
        }

        if (val[i] != val[i - 1] + 1)
            n = val[i] - 1;
    }
    cout<<n<<" "<<m;
    return 0;
}