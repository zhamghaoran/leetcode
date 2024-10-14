#include "bits/stdc++.h"

using namespace std;
int n, m;
char mapp[20][20];
int ans = 0x3f3f3f3f;

void dfs(int x, int y, set<int> sp, int step) {
    if (x == n && y == m) {
        ans = min(ans, step);
        return;
    }
    if (mapp[x + 1][y] == '*' && x + 1 <= n) {
        dfs(x + 1, y, sp, step + 1);
    }
    if (mapp[x][y + 1] == '*' && y + 1 <= m) {
        dfs(x, y + 1, sp, step + 1);
    }
    for (int i = y + 2; i <= m; i++) {
        if (mapp[x][i] == '*' && !sp.count(i - y)) {
            sp.insert(i - y);
            dfs(x, i, sp, step + 1);
            sp.erase(i - y);
        }
    }
    for (int i = x + 2; i <= n; i++) {
        if (mapp[i][y] == '*' && !sp.count(i - x)) {
            sp.insert(i - x);
            dfs(i, y, sp, step + 1);
            sp.erase(i - x);
        }
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mapp[i][j];
        }
    }
    set<int> faq;
    dfs(0, 0, faq, 0);
    if (ans == 0x3f3f3f3f)
        ans = -1;
    cout << ans;
    return 0;
}
