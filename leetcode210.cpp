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

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        for (auto i: prerequisites) {
            add(i[0], i[1]);
            du[i[1]]++;
        }
        queue<int> qu;
        cnt = 0;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!du[i]) {
                qu.push(i);
                ans.push_back(i);
                cnt++;
            }

        }
        while (!qu.empty()) {
            auto x = qu.front();
            qu.pop();
            for (int i = head[x]; i; i = rt[i].nex) {
                du[rt[i].t]--;
                if (du[rt[i].t] == 0) {
                    qu.push(rt[i].t);
                    cnt++;
                    ans.push_back(rt[i].t);
                }
            }
        }
        if (cnt == numCourses) {
            std::reverse(ans.begin(),ans.end());
            return ans;
        }
        ans.clear();
        return ans;
    }
};

int main() {
    return 0;
}