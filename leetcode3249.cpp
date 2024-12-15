#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    struct node {
        int f, t, nex;
    } rt[1000100];
    int head[100100];
    int cnt = 0;
    int siz[1000100];

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int countGoodNodes(vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            add(edges[i][0], edges[i][1]);
            add(edges[i][1], edges[i][0]);
        }
        dfs(0, 0);
        return dfs1(0, 0);
    }

    void dfs(int x, int f) {
        siz[x] = 1;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                dfs(rt[i].t, x);
                siz[x] += siz[rt[i].t];
            }
        }
    }

    int dfs1(int x, int f) {
        int same = 0;
        bool find = true;
        int ans = 0;
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f){
                ans += dfs1(rt[i].t, x);
                if (same == 0) {
                    same = siz[rt[i].t];
                } else if (same != siz[rt[i].t]) {
                    find = false;
                }
            }
        }
        if (find) {
            ans += 1;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{0, 1},
                               {0, 2},
                               {1, 3},
                               {1, 4},
                               {2, 5},
                               {2, 6}};
    cout << (new Solution)->countGoodNodes(faq);
    return 0;
}