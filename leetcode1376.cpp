#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ans;
    vector<vector<int>> qaq;
    vector<int> inf;
    int dfs(int x) {
        int maxx = 0;
        for (int i : qaq[x]) {
            maxx = max(maxx, dfs(i) + inf[x]);
        }
        return maxx;
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        ans = 0;
        inf = informTime;
        qaq = vector<vector<int>>(n, vector<int>(0));
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] == -1) {
                continue;
            }
            qaq[manager[i]].push_back(i);
        }
        return dfs(headID);
    }
};


int main() {
    vector<int> qaq = {2,2,-1,2,2,2};
    vector<int> faq = {0,0,1,0,0,0};
    cout<<(new Solution)->numOfMinutes(6,2,qaq,faq);
    return 0;
}