#include "bits/stdc++.h"
using namespace std;
int main() {
    vector<int> val;
    int x;
    for (int i = 1;i <= 10;i ++)
        scanf("%d",&x),val.push_back(x);
    vector<int> ji;
    vector<int> ou;
    std::for_each(val.begin(),val.end(),[&](auto x) -> bool  {
        if (x & 1)
            ji.push_back(x);
        else ou.push_back(x);
    });
    std::sort(ji.begin(), ji.end(),[&](int a,int b) -> bool {return a > b;});
    std::sort(ou.begin(), ou.end());
    std::for_each(ji.begin(), ji.end(), [&](const auto &item) {
        cout<<item<<" ";
    });
    std::for_each(ou.begin(), ou.end(), [&](const auto &item) {
        cout<<item<<" ";
    });
    return 0;
}