#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        vector<vector<int>> ans;
        vector<vector<int>> mapp(8, vector<int>(8, 0));
        for (auto i: queens) {
            mapp[i[0]][i[1]] = 1;
        }
        int x = king[0];
        int y = king[1];
        for (int i = x + 1; i < 8; i++) {
            if (mapp[i][y] == 1) {
                ans.push_back(vector<int>{i, y});
                break;
            }
        }
        for (int i = x - 1; i >= 0; i--) {
            if (mapp[i][y] == 1) {
                ans.push_back(vector<int>{i, y});
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (mapp[x][i] == 1) {
                ans.push_back(vector<int>{x, i});
                break;
            }
        }
        for (int i = y + 1; i < 8; i++) {
            if (mapp[x][i] == 1) {
                ans.push_back(vector<int>{x, i});
                break;
            }
        }
        for (int i = 1; x + i < 8 && y + i < 8; i++) {
            if (mapp[x + i][y + i] == 1) {
                ans.push_back(vector<int>{x + i, y + i});
                break;
            }
        }
        for (int i = 1; x - i >= 0 && y + i < 8; i++) {
            if (mapp[x - i][y + i] == 1) {
                ans.push_back(vector<int>{x - i, y + i});
                break;
            }
        }
        for (int i = 1; x + i < 8 && y - i >= 0; i++) {
            if (mapp[x + i][y - i] == 1) {
                ans.push_back(vector<int>{x + i, y - i});
                break;
            }
        }
        for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
            if (mapp[x - i][y - i] == 1) {
                ans.push_back(vector<int>{x - i, y - i});
                break;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
/*
[[0,4],[3,7]]
[[1,4],[3,7]]
 */