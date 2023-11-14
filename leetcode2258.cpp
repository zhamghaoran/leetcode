#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> fire;
    vector<vector<int>> neww;
    int a;
    int b;
    vector<vector<int>> wall;
    vector<int> fa;

    int fin(int x) {
        if (fa[x] != x)
            return fa[x] = fin(fa[x]);
        return fa[x];
    }

    void unin(int x, int y) {
        x = fin(x);
        y = fin(y);
        fa[x] = y;
    }

    int maximumMinutes(vector<vector<int>> &grid) {
        wall = grid;
        a = grid.size() - 1;
        b = grid[0].size() - 1;
        fa = vector<int>((a + 1) * (b + 1) + 1);
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (grid[i][j] == 1)
                    fire.emplace_back(i, j);
            }
        }
        int l = 0;
        int r = 300;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                l = mid - 1;
            else r = mid;
        }
        return l - 1;
    }

    int trans(int x, int y) {
        return x * b + y;
    }

    bool check(int x) {
        neww.resize(a, vector<int>(b));
        for (auto i: fire) {
            kuo(i.first, i.second, x);
        }
        for (int i = 0; i <= a; i++) {
            for (int j = 1; j <= b; j++)
                fa[trans(i, j)] = trans(i, j);
        }
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if (neww[i][j] == 0) {
                    if (i - 1 >= 0 && neww[i - 1][j] == 0)
                        unin(trans(i, j), trans(i - 1, j));
                    if (i + 1 <= a && neww[i + 1][j] == 0)
                        unin(trans(i, j), trans(i + 1, j));
                    if (j - 1 >= 0 && neww[i][j - 1] == 0)
                        unin(trans(i, j), trans(i, j - 1));
                    if (j + 1 <= b && neww[i][j + 1] == 0)
                        unin(trans(i, j), trans(i, j + 1));
                }
            }
        }
        return fin(trans(0, 0)) == fin(trans(a, b));
    }

    void kuo(int x, int y, int num) {
        int i = 0;
        neww[x][y] = 1;
        while (i <= num && y + i <= b) {
            if (wall[x][y + i] != 2) {
                neww[x][y + i] = 1;
            } else break;
            i++;
        }
        i = 0;
        while (i <= num && y - i >= 0) {
            if (wall[x][y - i] != 2) {
                neww[x][y + i] = 1;
            } else break;
            i++;
        }
        i = 0;
        while (i <= num && x + i <= a) {
            if (wall[x + i][y] != 2)
                neww[x + i][y] = 1;
            else break;
            i++;
        }
        i = 0;
        while (i <= num && x - i >= 0) {
            if (wall[x - i][y] != 2)
                neww[x - i][y] = 1;
            else break;
            i--;
        }

    }
};

int main() {
    return 0;
}