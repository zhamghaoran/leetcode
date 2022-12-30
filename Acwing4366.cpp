#include "bits/stdc++.h"
using namespace std;
void solve() {
    int a;
    cin>>a;
    vector<int> val(a + 1);
    int summ[100010];
    memset(summ,0,sizeof summ);
    int sum = 0;
    int maxx = 0;
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&val[i]);
        sum += val[i];
        maxx = max(maxx,val[i]);
        summ[i] = summ[i - 1] + val[i];

    }

    if (maxx == 0) {
        cout<<0<<endl;
        return;
    }
    for (int i = maxx;i <= sum;i ++) {
        if (sum % i == 0) {
            bool faq = false;
            for (int j = 1;j <= a;j ++) {
                int r = std::lower_bound(summ + j,summ + a + 1,i + summ[j - 1]) - summ;
                if (summ[r] - summ[j - 1] != i)
                    break;
                if (r == a)
                    faq = true;
                j = r;
            }
            if (faq) {
                cout<<a - sum / i<<endl;
                return;
            }
        }

    }
}
int main() {
    int t;
    cin>>t;
    while (t --) {
        solve();
    }
    return 0;
}