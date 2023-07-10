#include "bits/stdc++.h"

using namespace std;
int val[100010];
int tree[100010];
int b;

int lowbbit(int x) {
    return x & (-x);
}

void add(int x, int num) {
    while (num <= b) {
        tree[num] += x;
        num += lowbbit(num);
    }
}

int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += tree[x];
        x -= lowbbit(x);
    }
    return ans;
}

// 二分长度
int erfen(int x) {
    int l = 0;
    int r = x;
    auto pd = [&](int mid) -> bool {
        return sum(r) - sum(r - mid - 1) >= 0;
    };
    while (l < x) {
        int mid = (l + r + 1) >> 1;
        if (pd(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return sum(x) - sum(x - l - 1);
}

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        cin >> b;
        memset(tree, 0, sizeof tree);
        int x;
        for (int j = 1; j <= b; j++)
            scanf("%d", &val[j]), add(val[j], j);
        long long sum = 0;
        for (int j = 1; j <= b; j++) {
            if (val[j] >= 0) {
                sum += erfen(j);
            }
        }
        printf("Case #%d: %lld\n", i, sum);
    }

    return 0;
}