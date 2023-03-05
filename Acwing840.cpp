#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    set<int> faq;
    for (int i = 1;i  <= a;i ++) {
        char x;
        cin>>x;
        int b;
        cin>>b;
        if (x == 'I') {
            faq.insert(b);
        } else {
            if (faq.count(b))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}