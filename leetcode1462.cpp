#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<vector<int>> g(numCourses);
        vector<int> indgree(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (auto &p: prerequisites) {
            ++indgree[p[1]];
            g[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indgree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto &ne: g[cur]) {
                isPre[cur][ne] = true;
                for (int i = 0; i < numCourses; ++i) {
                    isPre[i][ne] = isPre[i][ne] | isPre[i][cur];
                }
                --indgree[ne];
                if (indgree[ne] == 0) {
                    q.push(ne);
                }
            }
        }
        vector<bool> res;
        for (auto &query: queries) {
            res.push_back(isPre[query[0]][query[1]]);
        }
        return res;
    }
};


int main() {
    vector<vector<int>> faq = {{2, 3},
                               {2, 1},
                               {2, 0},
                               {3, 4},
                               {3, 6},
                               {5, 1},
                               {5, 0},
                               {1, 4},
                               {1, 0},
                               {4, 0},
                               {0, 6}};
    vector<vector<int>> qaq = {{3, 0},
                               {6, 4},
                               {5, 6},
                               {2, 6},
                               {2, 3},
                               {5, 6},
                               {4, 0},
                               {2, 6},
                               {3, 5},
                               {5, 3}};
    (new Solution)->checkIfPrerequisite(7, faq, qaq);
    return 0;
}