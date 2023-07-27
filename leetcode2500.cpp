#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        int ans = 0;
        std::for_each(grid.begin(), grid.end(), [&](vector<int> &faq) -> void {
            std::sort(faq.begin(), faq.end(), [&](int a, int b) -> bool {
                return a > b;
            });
        });
        int a = grid[0].size();
        for (int i = 0; i < a; i++) {
            int maxx = -0x3f3f3f3f;
            for (int j = 0; j < grid.size(); j++) {
                maxx = max(maxx, grid[j][i]);
            }
            ans += maxx;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> qaq = {{1,2,4},{3,3,1}};
    (new Solution)->deleteGreatestValue(qaq);
    return 0;
}