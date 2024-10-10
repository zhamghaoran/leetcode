#include "bits/stdc++.h"

using namespace std;

class TreeAncestor {
public:
    struct node {
        int t, nex;
    } rt[200010];
    int head[50010];
    int cnt;
    int fa[50010][20];

    void add(int x, int y) {
        rt[++cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    void dfs(int x) {
        fa[x][0] = x;
        for (int i = head[x]; i; i = rt[i].nex) {
            fa[rt[i].t][1] = x;
            for (int j = 2; j < 20; j++) {
                if (fa[x][j - 1] == -1)
                    break;
                fa[rt[i].t][j] = fa[fa[rt[i].t][j - 1]][j - 1];
            }
            dfs(rt[i].t);
        }
    }


    TreeAncestor(int n, vector<int> &parent) {
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                add(parent[i], i);
            }
        }
        memset(fa, -1, sizeof fa);
        dfs(0);
    }

    int getKthAncestor(int node, int k) {
        vector<int> qaq;
        int faq = 1;
        while (k) {
            if (k & 1)
                qaq.push_back(faq);
            k >>= 1;
            faq ++;
        }
        int ans = node;
        for (int i: qaq) {
            ans = fa[ans][i];
            if (ans == -1)
                return -1;
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(Node,k);
 */
int main() {

    vector<int> faq = {-1, 0, 0, 1, 1, 2, 2};
    auto obj = new TreeAncestor(7, faq);
    cout << obj->getKthAncestor(5, 2);
    return 0;
}