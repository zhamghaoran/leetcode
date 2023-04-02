#include "bits/stdc++.h"
using namespace std;
int main() {
    string a,b;
    vector<int> faq,qaq;
    cin>>a>>b;
    for (int i  = 0;i <a.size();i ++) {
        if (a[i] == '*')
            faq.push_back(1);
        else
            faq.push_back(0);
        if (b[i] == '*')
            qaq.push_back(1);
        else
            qaq.push_back(0);
    }
    int ans = 0;
    for (int i = 0;i < a.size();i ++) {
        if (faq[i] != qaq[i]) {
            ans ++;
            faq[i] = 1 - faq[i];
            faq[i + 1] = 1 - faq[i + 1];
        }
    }
    cout<<ans;
    return 0;
}