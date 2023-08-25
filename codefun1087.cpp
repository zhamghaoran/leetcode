#include "bits/stdc++.h"

using namespace std;
int xx[2000];
int yy[2000];
int maxx;
int sum[2000][2000];
int mapp[2000][2000];
int n, a, b;
int x, y;
int maxxx;
int maxxy;

int main() {

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &xx[i], &yy[i]);
        maxxx = max(maxxx, xx[i]);
        maxxy = max(maxxy, yy[i]);
        sum[xx[i]][yy[i]] = 1;
    }
    for (int i = 1; i <= 1009 - a; i++) {
        for (int j = 1; j <= 1009 - b; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int nx = xx[i] + a;
        int ny = yy[i] + b;
        maxx = max(maxx, sum[nx][ny] - sum[xx[i] - 1][ny] - sum[nx][yy[i] - 1] + sum[xx[i] - 1][yy[i] - 1]);
    }
    cout << maxx;
    return 0;

}