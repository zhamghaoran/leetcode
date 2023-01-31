#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>> &grid) {
        bool ans = true;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == j) {
                    if (grid[i][j] == 0)
                        ans = false;
                }
                else if (i + j == grid.size() - 1){
                    if (grid[i][j] == 0)
                        ans = false;
                }
                else if (grid[i][j] != 0)
                    ans = false;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{2, 0, 0, 1},
                               {0, 3, 1, 0},
                               {0, 5, 2, 0},
                               {4, 0, 0, 2}};
    cout<<(new Solution)->checkXMatrix(faq);
    return 0;
}