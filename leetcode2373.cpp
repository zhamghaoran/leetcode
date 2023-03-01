#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int a = grid.size();
        int b = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < a - 2; i++) {
            vector<int> dis;
            for (int j = 0; j < b - 2; j++) {
                int maxx = 0;
                for (int xx = 0; xx < 3; xx++) {
                    for (int yy = 0; yy < 3; yy++) {
                        maxx = max(maxx, grid[i + xx][j + yy]);
                    }
                }
                dis.push_back(maxx);
            }
            ans.push_back(dis);
        }
        return ans;
    }
};

int main() {
    return 0;
}