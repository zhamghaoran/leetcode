#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex, val;
    } rt[10010];
    int head[100010];
    int cnt;
    int val[100010];

    void add(int x, int y, int z) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].val = z;
        rt[cnt].nex = head[x];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target) {
        queue<pair<int, vector<int> > > qu;
        std::for_each(edges.begin(), edges.end(), [&](vector<int> qaq) -> void {
            add(qaq[0], qaq[1], qaq[2]);
            add(qaq[1], qaq[0], qaq[2]);
        });
        memset(val, 0x3f, size(val));
        val[source] = 0;
        qu.emplace(source, vector<int>(0));
        while (!qu.empty()) {
            auto faq = qu.front();
            qu.pop();
            for (int i = head[faq.first]; i; i = rt[i].nex) {
                if (rt[i].val != -1) {
                    if (val[rt[i].t] > val[faq.first] + rt[i].val) {
                        qu.emplace(rt[i].t, faq.second);
                        val[rt[i].t] = val[faq.first] + rt[i].val;
                    }
                } else {
                    val[rt[i].t] = val[faq.first];
                    faq.second.push_back((i + 1) >> 1);
                    qu.emplace(rt[i].t, faq.second);
                }
            }
        }
    }
};

int main() {
    return 0;
}