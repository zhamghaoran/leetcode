#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    struct node {
        int f, t, nex;
    } rt[100010];
    int head[100010];
    int cnt;
    int du[100010];

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int minNumberOfSemesters(int n, vector<vector<int>> &relations, int k) {
        for (auto re: relations) {
            add(re[0], re[1]);
            du[re[1]]++;
        }
        queue<int> qaq, faq;
        for (int i = 1; i <= n; i++)
            if (du[i] == 0)
                qaq.push(i);
        int ans = 0;
        while (!qaq.empty()) {
            vector<int> pre;
            for (int i = 1; i <= k; i++) {
                if (qaq.empty())
                    break;
                pre.push_back(qaq.front());
                qaq.pop();
            }
            ans++;
            std::for_each(pre.begin(), pre.end(), [&](int a) -> void {
                for (int i = head[a]; i; i = rt[i].nex) {
                    du[rt[i].t]--;
                    if (du[rt[i].t] == 0)
                        qaq.push(rt[i].t);
                }
            });
        }
        return ans;
    }

};

int main() {
    return 0;

}