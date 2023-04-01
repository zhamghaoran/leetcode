#include "bits/stdc++.h"
#define int long long
using namespace std;
int val[200010];
struct node {
    int l, r, minn, add;
} rt[1000100];

void build(int l, int r, int num) {
    rt[num].l = l;
    rt[num].r = r;
    rt[num].add = 0;
    if (l == r) {
        rt[num].minn = val[l];
    } else {
        build(l, (l + r) >> 1, num << 1);
        build(((l + r) >> 1) + 1, r, num << 1 | 1);
        rt[num].minn = min(rt[num << 1].minn, rt[num << 1 | 1].minn);
    }
}

void change(int l, int r, int num, int vall) {
    if (rt[num].l == l && rt[num].r == r) {
        rt[num].minn += vall;
        rt[num].add += vall;
    } else {
        int mid = (rt[num].l + rt[num].r) >> 1;
        if (r <= mid) {
            change(l, r, num << 1, vall);
        } else if (l > mid)
            change(l, r, num << 1 | 1, vall);
        else {
            change(l, mid, num << 1, vall);
            change(mid + 1, r, num << 1 | 1, vall);
        }
        rt[num].minn = min(rt[num << 1].minn, rt[num << 1 | 1].minn);
    }
}

int ans = 0;

void query(int l, int r, int num, int calc) {
    if (l == rt[num].l && r == rt[num].r) {
        ans = min(ans, rt[num].minn + calc);
        return;
    }
    calc += rt[num].add;
    int mid = (rt[num].l + rt[num].r) >> 1;
    if (r <= mid) {
        query(l, r, num << 1, calc);
    } else if (l > mid)
        query(l, r, num << 1 | 1, calc);
    else {
        query(l, mid, num << 1, calc);
        query(mid + 1, r, num << 1 | 1, calc);
    }
}

signed main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &val[i]);
    }
    build(1, a, 1);
    int b;
    cin >> b;
    int x, y, z;
    char xx;
    while (b--) {
        scanf("%lld%lld%c", &x, &y, &xx);
        if (xx == '\n') {
            ans = 0x3f3f3f3f;
            if (x > y) {
                query(x + 1, a, 1, 0);
                query(1, y + 1, 1, 0);
            } else
                query(x + 1, y + 1, 1, 0);
            printf("%lld\n", ans);
        } else {
            scanf("%lld", &z);
            if (x > y) {
                change(x + 1, a, 1, z);
                change(1, y + 1, 1, z);
            } else {
                change(x + 1, y + 1, 1, z);
            }
        }
    }
    return 0;
}
/**
*
-999704
-999998
-999844
-197009
-197008
-2077186
-2230879

-999704
-999998
-999844
-197009
-197008
-1738714
*/