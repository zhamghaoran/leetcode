#include "bits/stdc++.h"

using namespace std;
int tx[4] = {0,1,0,-1};
int ty[4] = {1,0,-1,0};
int mapp[10][10];
int a, b, c;
int ans;

map<int, int> mark;

void dfs(int xx, int yy, int cnt, int tem) {
    if (cnt > c) {
        if (!mark[tem])
            ans++;
        mark[tem] = 1;
        return;
    }
    for (int i = 0;i < 4;i ++) {
        int nx = xx + tx[i];
        int ny = yy + ty[i];
        if (nx <= a && nx > 0 && ny <= b && ny > 0) {
            dfs(nx,ny,cnt + 1,tem * 10 + mapp[nx][ny]);
        }
    }
}

int main() {

    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> mapp[i][j];
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++)
            dfs(i, j, 0, 0);
    }
    cout << ans;
    return 0;
}