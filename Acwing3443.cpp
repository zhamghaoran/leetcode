#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    int xuefen[100010];
    int fenshu[100010];
    cin>>a;
    int sum = 0;
    for (int i = 1;i<= a;i ++) {
        cin>>xuefen[i];
        sum += xuefen[i];
    }

    for (int i = 1;i <= a;i ++)
        cin>>fenshu[i];
    double ans = 0.00;
    for (int i = 1;i <= a;i ++) {
        if (fenshu[i] >= 90)
            ans += 4.0 * xuefen[i];
        else if (fenshu[i] >= 85)
            ans += 3.7 * xuefen[i];
        else if (fenshu[i] >= 82)
            ans += 3.3 * xuefen[i];
        else if (fenshu[i] >= 78)
            ans += 3.0 * xuefen[i];
        else if (fenshu[i] >= 75)
            ans += 2.7 * xuefen[i];
        else if (fenshu[i] >= 72)
            ans +=  2.3 * xuefen[i];
        else if (fenshu[i] >= 68)
            ans += 2.0 * xuefen[i];
        else if (fenshu[i] >= 64)
            ans += 1.5 * xuefen[i];
        else if (fenshu[i] >= 60)
            ans += 1.0 * xuefen[i];
        else
            ans += 0.00;
    }
    printf("%.2lf",ans / sum);
    return 0;
}