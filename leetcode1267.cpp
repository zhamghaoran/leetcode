#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        vector<int> lie(251, 0);
        vector<int> hang(251, 0);
        vector<vector<int>> vis(251, vector<int>(251, 0));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    hang[i]++;
                    lie[j]++;
                }
            }
        }
        for (int i = 0;i < grid.size();i ++) {
            for (int j = 0;j < grid[0].size();j ++) {
                if (grid[i][j] == 1 && (hang[i] > 1 || lie[j] > 1))
                    ans ++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> qaq = {{1, 0},
                               {1, 1}};
    cout << (new Solution)->countServers(qaq);
    return 0;
}