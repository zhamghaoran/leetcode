#include "bits/stdc++.h"

using namespace std;
int xx[1010];
int yy[1010];
int maxx;
int sum[1010][1010];
int mapp[1010][1010];
int n, a, b;
int x, y;

int main() {

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        sum[x][y] = 1;
    }
    for (int i = 1; i <= 1009; i++) {
        for (int j = 1; j <= 1009; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= 1009 - a; i++) {
        for (int j = 1; j <= 1009 - b; j++) {
            int nx = i + a;
            int ny = j + b;
            maxx = max(maxx, sum[nx][ny] - sum[i - 1][ny] - sum[nx][j - 1] + sum[i - 1][j - 1]);
        }
    }
    cout << maxx;
    return 0;

}