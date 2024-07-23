#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex;
    } rt[1000010];
    int head[1000010];
    int cnt;

    void add(int f, int t) {
        rt[++cnt].f = f;
        rt[cnt].t = t;
        rt[cnt].nex = head[f];
        head[f] = cnt;
    }

    void judege(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2, int i, int j) {
        double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (r1 >= dis) {
            add(i, j);
        }
        if (r2 >= dis) {
            add(j, i);
        }
    }

    int vis[10010];
    int ans = 0;
    int max = 0;

    void dfs(int x) {
        vis[x] = 1;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (!vis[rt[i].t]) {
                cnt++;
                dfs(rt[i].t);
            }
        }
    }

    int maximumDetonation(vector<vector<int>> &bombs) {
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = i + 1; j < bombs.size(); j++) {
                judege(bombs[i][0], bombs[i][1], bombs[i][2], bombs[j][0], bombs[j][1], bombs[j][2], i, j);
            }
        }
        ans = 1;
        max = 1;
        for (int i = 0; i < bombs.size(); i++) {
            memset(vis, 0, sizeof vis);
            cnt = 1;
            dfs(i);
            if (cnt > max) {
                max = cnt;
                ans = i + 1;
            }
        }
        return max;
    }
};




int main() {
    vector<vector<int>> res = {{1,  1,  100},
                               {81, 61, 60}};
    int ans = (new Solution)->maximumDetonation(res);
    cout << ans;
    return 0;
}