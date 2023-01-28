#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        int ans[a][b];
        int lie[a][b];
        int hang[a][b];
        for (int i = 0;i < a;i ++) {
            int minn = 0x3f3f3f3f;
            int mark;
            for (int j = 0;j < b;j ++) {
                if (matrix[i][j] > minn) {
                    minn = matrix[i][j];
                    mark = j;
                }
            }
        }

    }
};
int main() {
    return 0;
}