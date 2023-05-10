#include "bits/stdc++.h"

using namespace std;
int lie[10][10];
int hang[10][10];
int val[10][10];
vector<vector<pair<int, int>>> huafen(7, vector<pair<int, int>>(0));

void pr() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++)
            cout << val[i][j] << " ";
        puts("");
    }
}

void dfs(int x, int y) {
    if (x == 6 && y == 6) {
        for (int i = 1; i <= 6; i++) {
            int faq[7];
            memset(faq, 0, sizeof faq);
            for (auto &j: huafen[i]) {
                if (!faq[val[j.first][j.second]])
                    faq[val[j.first][j.second]] = 1;
                else
                    return;
            }
        }
        pr();
    }
    if (x + 1 <= 6) {
        if (val[x + 1][y] != 0) {
            lie[y][val[x + 1][y]] = 1;
            hang[x + 1][val[x + 1][y]] = 1;
            dfs(x + 1, y);
            lie[y][val[x + 1][y]] = 0;
            hang[x + 1][val[x + 1][y]] = 1;
        } else {
            for (int i = 1; i <= 6; i++) {
                if (!hang[x + 1][i] && !lie[y][i]) {
                    val[x + 1][y] = i;
                    hang[x + 1][i] = 1;
                    lie[y][i] = 1;
                    dfs(x + 1, y);
                    hang[x + 1][i] = 0;
                    lie[y][i] = 0;
                    val[x + 1][y] = 0;
                }
            }
        }
    }
    if (y + 1 <= 6) {
        if (val[x][y + 1] != 0) {
            lie[y + 1][val[x][y + 1]] = 1;
            hang[x][val[x][y + 1]] = 1;
            dfs(x, y + 1);
            lie[y + 1][val[x][y]] = 0;
            hang[x][val[x][y + 1]] = 1;
        } else {
            for (int i = 1; i <= 6; i++) {
                if (!hang[x][i] && !lie[y + 1][i]) {
                    val[x][y + 1] = i;
                    hang[x][i] = 1;
                    lie[y + 1][i] = 1;
                    dfs(x, y + 1);
                    hang[x][i] = 0;
                    lie[y + 1][i] = 0;
                    val[x][y + 1] = 0;
                }
            }
        }
    }
}

int main() {

    int x;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cin >> x;
            if (x != 0)
                val[i][j] = x;
        }
    }

    huafen[1].emplace_back(1, 1);
    huafen[1].emplace_back(1, 2);
    huafen[1].emplace_back(1, 3);
    huafen[1].emplace_back(2, 1);
    huafen[1].emplace_back(2, 2);
    huafen[1].emplace_back(3, 1);
    huafen[2].emplace_back(1, 4);
    huafen[2].emplace_back(1, 5);
    huafen[2].emplace_back(1, 6);
    huafen[2].emplace_back(2, 3);
    huafen[2].emplace_back(2, 4);
    huafen[2].emplace_back(2, 5);
    huafen[3].emplace_back(3, 2);
    huafen[3].emplace_back(3, 3);
    huafen[3].emplace_back(3, 4);
    huafen[3].emplace_back(4, 1);
    huafen[3].emplace_back(4, 2);
    huafen[3].emplace_back(5, 1);
    huafen[4].emplace_back(6, 1);
    huafen[4].emplace_back(6, 2);
    huafen[4].emplace_back(6, 3);
    huafen[4].emplace_back(5, 2);
    huafen[4].emplace_back(5, 3);
    huafen[4].emplace_back(5, 4);
    huafen[5].emplace_back(2, 6);
    huafen[5].emplace_back(3, 6);
    huafen[5].emplace_back(3, 5);
    huafen[5].emplace_back(4, 3);
    huafen[5].emplace_back(4, 4);
    huafen[5].emplace_back(4, 5);
    huafen[6].emplace_back(6, 4);
    huafen[6].emplace_back(6, 5);
    huafen[6].emplace_back(6, 6);
    huafen[6].emplace_back(5, 5);
    huafen[6].emplace_back(5, 6);
    huafen[6].emplace_back(4, 6);
    if (val[1][1] != 0) {
        hang[1][val[1][1]] = 1;
        lie[1][val[1][1]] = 1;
        dfs(1, 1);

    } else {
        for (int i = 1; i <= 6; i++) {
            hang[1][i] = i;
            lie[1][i] = i;
            val[1][1] = i;
            dfs(1, 1);
            hang[1][i] = 0;
            lie[1][i] = 0;
        }
    }

    return 0;
}
/**
1 0 0 4 0 2
2 3 0 0 0 0
0 1 0 2 0 0
0 0 2 0 1 0
0 0 0 0 4 5
5 0 4 0 0 1
*/