#include "bits/stdc++.h"

using namespace std;
int val[300010];
int ans[300010];
int qaq[300010];

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &val[i]);
        qaq[val[i]] = 1;
    }
//    int faq = maxx / minn + 1;
//    for (int j = 1; j <= faq; j++) {
//        for (int i = 1; i <= a; i++) {
//            if (val[i] * j <= maxx && qaq[val[i] * j]) {
//                ans[j] = 1;
//                break;
//            }
//        }
//    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= val[i] / j + 1; j++) {
            int x = val[i] / j;
            if (val[i] % j == 0 && qaq[x]) {
                ans[j] = 1;
            }
            if (val[i] % j == 0 && qaq[j])
                ans[x] = 1;
        }
    }
    int x;
    for (int i = 1; i <= b; i++) {
        scanf("%d", &x);
        if (ans[x])
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}