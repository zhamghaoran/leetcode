#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex;
    } rt[1000010];
    int head[100010];
    int cnt = 0;
    vector<int> val;

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int root;
    int minn;
    int sum;
    vector<int> ans;
    vector<int> siz;

    void dfs(int x, int f) {
        int maxx = -10;
        siz[x] += val[x];
        for (int i = head[x]; i; i = rt[i].nex) {
            if (rt[i].t != f) {
                dfs(rt[i].t, x);
                if (ans[rt[i].t] > 0) {
                    ans[x] += ans[rt[i].t];
                }
                maxx = max(maxx, ans[rt[i].t]);
                siz[x] += siz[rt[i].t];
            }
        }
        if (maxx < 0) {
            ans[x] = maxx + 1;
        }
        if (val[x])
            ans[x] = max(ans[x], -2);
        int tem_max = max(siz[x], sum - siz[x]);
        if (tem_max < minn) {
            minn = tem_max;
            root = x;
        }
    }

    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        val = vector<int>(coins.begin(), coins.end());
        for (auto i: val) sum += i;
        siz = vector<int>(coins.size(), 0);
        minn = 0x3f3f3f3f;
        ans = vector<int>(coins.size(), 0);
        dfs(0, -1);
        int anss = 0;
        for (int i = head[root]; i; i = rt[i].nex) {
            anss += ans[rt[i].t] * 2;
        }
        cout<<root;
        return anss;
    }
};

int main() {
    return 0;
}