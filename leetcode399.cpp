#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        string f;
        string t;
        double val;
        int nex;
    } rt[100010];
    int cnt;
    unordered_map<string, int> head;

    void add(string x, string y, double val) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].val = val;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    bool find = false;
    double ans = 1.00;
    unordered_set<string> vis;

    void dfs(string now, string tar, double dans) {
        if (now == tar) {
            ans = dans;
            find = true;
            return;
        }
        for (int i = head[now]; i; i = rt[i].nex) {
            if (vis.count(rt[i].t)) {
                continue;
            }
            double val = rt[i].val;
            vis.emplace(rt[i].t);
            dfs(rt[i].t, tar, dans * val);
            vis.erase(rt[i].t);
        }
    }

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string x = equations[i][0];
            string y = equations[i][1];
            add(x, y, values[i]);
            add(y, x, 1.00 / values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (!head.count(queries[i][0]) || !head.count(queries[i][1])) {
                res.push_back(-1.00);
            } else {
                ans = 1.00;
                find = false;
                vis.emplace(queries[i][0]);
                dfs(queries[i][0], queries[i][1], 1.00);
                if (!find) {
                    res.push_back(-1.00);
                } else {
                    res.push_back(ans);
                }
                vis.erase(queries[i][0]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<string>> res = {{"a", "b"},
                                  {"b", "c"}};
    vector<double> val = {2.0, 3.0};
    vector<vector<string>> qu = {{"a", "c"},
                                 {"b", "a"},
                                 {"a", "e"},
                                 {"a", "a"},
                                 {"x", "x"}};
    (new Solution)->calcEquation(res, val, qu);

    return 0;
}