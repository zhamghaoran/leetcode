#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex, val;
    } rt[100010];
    int cnt;
    int head[100010];
    int a;

    int trans(int x, int y) const {
        return x * (a + 1) + y;
    }

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].val = 1;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        a = grid.size() - 1;
        if (a == 1) return 1;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= a; j++) {
                if (grid[i][j] == 1)
                    continue;
                if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                    add(trans(i, j), trans(i - 1, j));
                    add(trans(i - 1, j), trans(i, j));
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                    add(trans(i, j), trans(i, j - 1));
                    add(trans(i, j - 1), trans(i, j));
                }
                if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 0) {
                    add(trans(i, j), trans(i - 1, j - 1));
                    add(trans(i - 1, j - 1), trans(i, j));
                }
                if (i + 1 <= a && j - 1 >= 0 && grid[i + 1][j - 1] == 0)
                    add(trans(i, j), trans(i + 1, j - 1)), add(trans(i + 1, j - 1), trans(i, j));
            }
        }
        vector<int> ans((a + 1) * (a + 1) + 1, 0x3f3f3f3f);
        ans[0] = 0;
        priority_queue<pair<int, int>> qaq;
        qaq.emplace(0, 0);
        vector<int> vis((a + 1) * (a + 1) + 1, 0);
        while (!qaq.empty()) {
            auto x = qaq.top();
            qaq.pop();
            if (vis[x.second])
                continue;
            vis[x.second] = 1;
            for (int i = head[x.second]; i; i = rt[i].nex) {
                if (ans[rt[i].t] > ans[x.second] + 1) {
                    ans[rt[i].t] = ans[x.second] + 1;
                    qaq.emplace(-ans[rt[i].t], rt[i].t);
                }
            }
        }
        return ans[(a + 1) * (a + 1) - 1] >= 0x3f3f3f3f ? -1 : ans[(a + 1) * (a + 1) - 1] + 1;
    }
};

int main() {
    vector<vector<int>> qaq = {{0, 1, 1, 0, 0, 0},
                               {0, 1, 0, 1, 1, 0},
                               {0, 1, 1, 0, 1, 0},
                               {0, 0, 0, 1, 1, 0},
                               {1, 1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1, 0}};
    cout << (new Solution)->shortestPathBinaryMatrix(qaq);
    return 0;
}