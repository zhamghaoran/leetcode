#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int dfn[1020];
    int cnt = 0;
    struct node {
        int f;
        int t;
        int nex;
    };
    vector<int> head;
    vector<node> rt;

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        vector<int> du(edges.size() + 10, 0);
        rt = vector<node>(edges.size() + 10);
        head = vector<int>(edges.size() + 10);
        for (int i = 0; i < edges.size(); i++) {
            du[edges[i][1]]++;
            add(edges[i][0], edges[i][1]);
        }
        int root = 0;
        for (int i = 1; i < edges.size() + 1; i++) {
            if (!du[i]) {
                root = i;
                break;
            }
        }
        cnt = 0;
        for (int i = 0; i < edges.size() + 10; i++) {
            dfn[i] = 0x3f3f3f3f;
        }
        if (root != 0) {
            set<pair<int, int>> ans = bfs(root);
            for (int i = edges.size() - 1; i >= 0; i--) {
                if (ans.count(make_pair(edges[i][0], edges[i][1]))) {
                    return {edges[i][0], edges[i][1]};
                }
            }
            return edges[0];
        } else {
            set<pair<int, int>> ans;
            for (int i = 1; i < edges.size(); i++) {
                if (du[i] == 1) {
                    for (int j = 0; j < edges.size() + 10; j++) {
                        dfn[j] = 0x3f3f3f3f;
                    }
                    cnt = 0;
                    set<pair<int, int>> tem = bfs(i);
                    if (tem.size() == 0) {
                        continue;
                    }
                    for (int j = edges.size() - 1; j >= 0; j--) {
                        if (tem.count(make_pair(edges[j][0], edges[j][1]))) {
                            ans.insert(make_pair(edges[j][0], edges[j][1]));
                        }
                    }
                }
            }
            for (int j = edges.size() - 1; j >= 0; j--) {
                if (ans.count(make_pair(edges[j][0], edges[j][1]))) {
                    return {edges[j][0], edges[j][1]};
                }
            }
        }
        return edges[0];
    }

    set<pair<int, int>> bfs(int x) {
        set<pair<int, int>> ans;
        queue<int> qu;
        qu.push(x);
        while (!qu.empty()) {
            int now = qu.front();
            dfn[now] = ++cnt;
            qu.pop();
            for (int i = head[now]; i; i = rt[i].nex) {
                if (dfn[rt[i].t] == 0x3f3f3f3f) {
                    qu.push(rt[i].t);
                } else {
                    ans.insert(make_pair(now, rt[i].t));
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> node = {{1,2},
                                {2, 3},
                                {3, 1},
                                {4, 1}};
    vector<int> ans = (new Solution)->findRedundantDirectedConnection(node);
    cout << ans[0] << " " << ans[1];
    return 0;
}