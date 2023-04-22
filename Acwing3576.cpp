#include "bits/stdc++.h"

using namespace std;
int maxx;
struct node {
    int val, rt;
} rt[1000010];

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
        scanf("%d", &rt[i].val);
    for (int i = 1; i <= a; i++)
        scanf("%d", &rt[i].rt);
    std::sort(rt + 1, rt + 1 + a, [&](node c, node d) -> bool {
        if (c.rt == d.rt)
            return c.val < d.val;
        return c.rt < d.rt;
    });

    for (int i = 1;i <= a;i ++) {
        vector<int> tem;
        int j = i;
        while (rt[j].rt == rt[i].rt) {

        }
    }
    return 0;
}