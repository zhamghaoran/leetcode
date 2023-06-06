#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int ans = 0;
        map<string, int> mapp;
        int a = grid.size() - 1;
        for (int i = 0; i <= a; i++) {
            string tem;
            for (int j = 0; j <= a; j++) {
                tem += to_string(grid[i][j]);
                tem += ",";
            }
            mapp[tem]++;
        }
        for (int i = 0; i <= a; i++) {
            string tem;
            for (int j = 0; j <= a; j++) {
                tem += to_string(grid[j][i]);
                tem += ",";
            }
            ans += mapp[tem];
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{250, 78,  253},
                               {334, 252, 253},
                               {250, 253, 253}};
    cout<<(new Solution)->equalPairs(faq);
    return 0;
}