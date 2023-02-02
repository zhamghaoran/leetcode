#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, col, nex;
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<int> head(n + 1);
        vector<int> ans(n);
        vector<int> rans(n + 1, 0x3f3f3f3f);
        vector<int> bans(n + 1, 0x3f3f3f3f);
        queue<pair<pair<int, int>, int>> qu;      // val,nodeNum,color
        int cnt = 0;
        node rt[redEdges.size() + blueEdges.size() + 2];
        auto add = [&](int x, int y, int col) -> void {
            rt[++cnt].f = x;
            rt[cnt].t = y;
            rt[cnt].col = col;
            rt[cnt].nex = head[x];
            head[x] = cnt;
        };
        std::for_each(redEdges.begin(), redEdges.end(), [&](const auto &item) {
            add(item[0], item[1], 1);
        });
        std::for_each(blueEdges.begin(), blueEdges.end(), [&](const auto &item) {
            add(item[0], item[1], 0);
        });
        rans[0] = bans[0] = 0;
        qu.emplace(make_pair(0,0),1);
        qu.emplace(make_pair(0,0),0);
        while (!qu.empty()) {
            auto faq = qu.front();
            qu.pop();
            for (int i = head[faq.first.second];i;i = rt[i].nex) {
                if (faq.second == 1) {
                    if (bans[rt[i].t] > rans[faq.first.second] + 1 && rt[i].col == 0) {
                        bans[rt[i].t] = rans[faq.first.second] + 1;
                        qu.emplace(make_pair(bans[rt[i].t],rt[i].t),0);
                    }
                } else {
                    if (rans[rt[i].t] > bans[faq.first.second] + 1 && rt[i].col == 1) {
                        rans[rt[i].t] = bans[faq.first.second] + 1;
                        qu.emplace(make_pair(rans[rt[i].t],rt[i].t),1);
                    }
                }
            }
        }
        for (int i = 0;i < n;i ++) {
            if (rans[i] == 0x3f3f3f3f && bans[i] == 0x3f3f3f3f)
                ans[i] = -1;
            else {
                ans[i] = min(rans[i],bans[i]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> b = {{0,1},{1,2}};
    vector<vector<int>> c;
    vector<int> ans = (new Solution)->shortestAlternatingPaths(3,b,c);
    return 0;
}