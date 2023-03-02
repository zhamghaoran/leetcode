#include "bits/stdc++.h"

using namespace std;
int a;
char ans[20][20];
int lie[20];
int dui[20];
int dui1[20];

void dfs(int x) {
    if (x == a + 1) {
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= a; j++) {
                cout << ans[i][j];
            }
            puts("");
        }
        puts("");
        return;
    }
    for (int i = 1; i <= a; i++) {
        if (!lie[i] && !dui[a + x - i] && !dui1[x + i]) {
            lie[i] = 1;
            dui[a + x - i] = 1;
            dui1[x + i] = 1;
            ans[x][i] = 'Q';
            dfs(x + 1);
            ans[x][i] = '.';
            lie[i] = 0;
            dui[a + x - i] = 0;
            dui1[x + i] = 0;
        }
    }
}

int main() {
    cin >> a;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++)
            ans[i][j] = '.';
    }
    dfs(1);
    return 0;
}