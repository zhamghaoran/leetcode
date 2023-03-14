#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    int x,y;
    cin>>x>>y;
    set<double> qaq;
    int xx,yy;
    int ans = 0;
    bool faq = false;
    for (int i = 1;i <= a;i ++) {
        ::scanf("%d%d",&xx,&yy);
        if (xx - x != 0) {
            double xielv = 1.00 * (yy - y) / (xx - x);
            if (!qaq.count(xielv))
                ans ++;
            qaq.insert(xielv);
        }
        else faq = true;
    }
    if (faq)
        ans ++;
    cout<<ans;
    return 0;
}