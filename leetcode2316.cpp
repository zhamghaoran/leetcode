#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int fa[100010];
    int siz[100010];

    int fin(int x) {
        if (fa[x] != x)
            return fa[x] = fin(fa[x]);
        return fa[x];
    }

    void unin(int x, int y) {
        x = fin(fa[x]);
        y = fin(fa[y]);
        siz[y] += siz[x];
        fa[x] = y;
    }

    long long countPairs(int n, vector<vector<int>> &edges) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            siz[i] = 1;
        }
        std::for_each(edges.begin(), edges.end(), [&](const vector<int> faq) -> void {
            if (fin(faq[0]) != fin(faq[1])) {
                unin(faq[0], faq[1]);
            }
        });
        for (int i = 0; i < n; i++) {
            if (fa[i] == i) {
                ans += (long long)(n - siz[i]) * (long long)siz[i];
            }
        }
        return ans / 2;
    }
};

int main() {

    return 0;
}