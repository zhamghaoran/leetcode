#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct node {
        int f, t, nex;
    } rt[1000100];
    int head[1000100];
    int cnt;
    int du[1000100];

    void add(int x, int y) {
        rt[++cnt].f = x;
        rt[cnt].t = y;
        rt[cnt].nex = head[x];
        head[x] = cnt;
    }

    int dp[1000100];

    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        std::for_each(relations.begin(), relations.end(), [&](vector<int> a) -> void {
            add(a[0], a[1]);
            du[a[1]]++;
        });
        int ans = 0;
        queue<int> qaq;
        for (int i = 1; i <= n; i++) {
            if (!du[i])
                qaq.push(i), dp[i] = time[i - 1],ans = max(ans,dp[i]);
        }

        while (!qaq.empty()) {
            int x = qaq.front();
            qaq.pop();
            for (int i = head[x]; i; i = rt[i].nex) {
                dp[rt[i].t] = max(dp[rt[i].t], dp[x] + time[rt[i].t - 1]);
                ans = max(ans, dp[rt[i].t]);
                du[rt[i].t]--;
                if (!du[rt[i].t])
                    qaq.push(rt[i].t);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{1,3},{2,3}};
    vector<int> qaq = {3,2,5};
    cout<<(new Solution)->minimumTime(3,faq,qaq);
    return 0;
}