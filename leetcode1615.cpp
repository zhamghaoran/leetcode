#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> du(n + 1,0);
        vector<vector<int>> edge(105,vector<int> (105,0));
        for (auto i : roads) {
            du[i[0]] ++;
            du[i[1]] ++;
            edge[i[0]][i[1]] = 1;
            edge[i[1]][i[0]] = 1;
        }
        for (int i = 0;i < n;i ++) {
            for (int j = i + 1;j < n;j ++) {
                ans  = max(ans,du[i] + du[j] - edge[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}