#include <cstdio>

int main() {
    int a[10][10];
    for (int i = 1;i <= 3;i ++) {
        for (int j = 1;j <= 4;j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    int n;
    scanf("%d",&n);
    int ans = -99999;
    for (int i = 1;i <= 4;i ++) {
        if (ans < a[n][i])
            ans = a[n][i];
    }
    printf("%d",ans);
    return 0;
}