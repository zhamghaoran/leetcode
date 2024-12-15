#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int fa[100010];

    int fin(int x) {
        if (fa[x] == x) {
            return fa[x];
        } else {
            return fa[x] = fin(fa[x]);
        }
    }

    void unin(int x, int y) {
        x = fin(x);
        y = fin(y);
        fa[x] = y;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> ans;
        for (int i = 0; i <= edges.size(); i++) {
            fa[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (fin(edges[i][0]) != fin(edges[i][1])) {
                unin(fin(edges[i][0]), fin(edges[i][1]));
            } else {
                ans = edges[i];
            }
        }
        return ans;
    }
};

int main() {

}