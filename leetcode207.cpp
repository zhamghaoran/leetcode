#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex;
    } rt[10010];
    int head[10010];
    int cnt;

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    void dfs(int x) {
        cnt++;
        vis[x] = 1;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (!vis[rt[i].t]) {
                du[rt[i].t]--;
                if (!du[rt[i].t])
                    dfs(rt[i].t);
            }
        }
    }

    bool ans = false;
    vector<int> vis;
    vector<int> du;

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        du = vector<int>(numCourses, 0);
        vis = vector<int>(numCourses, 0);
        for (auto i: prerequisites) {
            add(i[0], i[1]);
            du[i[1]]++;
        }
        cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!du[i] && !vis[i]) {
                dfs(i);
            }
        }
        return cnt == numCourses;
    }
};

int main() {
    return 0;
}