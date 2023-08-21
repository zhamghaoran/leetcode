/*
 * 首先我们先算出来没有删除的情况下的值为多少，然后因为每经过一个销售人员，d的值就会重置，因此各个区间之间的独立的
 * 因此我们可以单独考虑每一个区间，如果删除了第i个销售人员，那么可以得到新的值为 res - 两个相邻区间的值加上，新的大区间的值
 * 然后记录一下最小值即可
 */
#include "bits/stdc++.h"

using namespace std;
int val[100010];

void solve() {

    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    for (int i = 1; i <= y; i++) {
        scanf("%d", &val[i]);
    }
    val[0] = 1 - z;
    val[y + 1] = x + 1;
    int res = 0;
    for (int i = 1; i <= y + 1; i++) {
        res += (val[i] - 1 - val[i - 1]) / z;
    }
    res += y;
    int minn = 0x3f3f3f3f;
    int ans = 0;
    for (int i = 1; i <= y; i++) {
        int tem = res - ((val[i] - 1 - val[i - 1]) / z + 1) - ((val[i + 1] - 1 - val[i]) / z + 1) +
                  ((val[i + 1] - 1 - val[i - 1]) / z + 1);
        if (tem < minn) {
            minn = tem;
            ans = 1;
        } else if (tem == minn)
            ans ++;
    }
    printf("%d %d\n", minn, ans);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}