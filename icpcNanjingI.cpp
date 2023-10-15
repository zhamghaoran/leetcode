#include "bits/stdc++.h"
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t --) {
        string a;
        cin>>a;
        map<char,int> faq;
        int maxx = 0;
        for (int i = 0;i < a.size();i ++) {
            faq[a[i]] ++;
            maxx = max(maxx,faq[a[i]]);
        }
        cout<<a.size() - maxx<<"\n";
    }
    return 0;
}