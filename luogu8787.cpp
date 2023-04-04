#include "bits/stdc++.h"

#define int long long
using namespace std;
int fa[1000010];
int val[1000010];
int ma[1000010];
int fin(int x) {
    if (fa[x] != x)
        return fa[x] = fin(fa[x]);
    return fa[x];
}

void unin(int x, int y) {
    x = fin(x);
    y = fin(y);
    fa[x] = y;
}

signed main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
        fa[i] = i;
    int ans = 0;
    priority_queue<pair<int, int> > faq;
    for (int i = 1; i <= a; i++) {
        ::scanf("%lld", &val[i]);
        if (val[i] == val[i - 1])
            unin(i, i - 1);
        else {
            ma[i] = val[i];
            faq.emplace(val[i], i);
        }
    }
    while (!faq.empty()) {
        int num = fin(faq.top().second);
        faq.pop();
        if (ma[num] != val[num])
            continue;
        if (val[num] == val[fin(num - 1)]) {
            while (num > 1 && val[num] == val[fin(num - 1)]) {
                unin(num,num - 1);
                num = fin(num);
            }
            continue;
        }
        if (val[num] <= 1)
            continue;

        val[num] = sqrt(val[num] / 2 + 1);
        int j = num + 1;
        while (val[j] == val[num]) {
            if (fa[j] != fa[num])
                unin(j ,num);
            j ++;
        }

        if (val[num] == val[fin(num - 1)]) {
            while (num > 1 && val[num] == val[fin(num - 1)]) {
                unin(num,num - 1);
                num = fin(num);
            }
        }
        else if (val[num] > 1) {
            ans ++;
            ma[num] = val[num];
            faq.emplace(val[num], num);
        }
    }
    cout << ans;
    return 0;
}