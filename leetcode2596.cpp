#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        map<int, pair<int, int>> faq;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                faq[grid[i][j]] = make_pair(i, j);
            }
        }
        pair<int, int> now = faq[0];
        auto pd = [&](pair<int, int> a, pair<int, int> b) -> bool {
            if ((abs(a.first - b.first) == 2 && abs(a.second - b.second) == 1) ||
                (abs(a.first - b.first) == 1 && abs(a.second - b.second) == 2))
                return true;
            return false;
        };
        if (now.first != 0 || now.second != 0) return false;
        for (int i = 1; i < grid.size() * grid[0].size(); i++) {
            if (!pd(now, faq[i]))
                return false;
            now = faq[i];
        }
        return true;
    }
};

int main() {

    return 0;
}
/*
24 11 22 17 4
21 16 5 12 9
6 23 10 3 18
15 20 1 8 13
0 7 14 19 2
 *
 */