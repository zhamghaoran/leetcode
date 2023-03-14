#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size(),0));
        for (int i = 0;i < rowSum.size();i ++) {
            for (int j = 0;j < colSum.size();j ++) {
                if (rowSum[i] <= 0 || colSum[j] <= 0)
                    continue;
                int x = min(rowSum[i],colSum[j]);
                ans[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> row = {5,7,10};
    vector<int> col = {8,6,8};
    vector<vector<int>> ans = (new Solution)->restoreMatrix(row,col);
    std::for_each(ans.begin(), ans.end(), [&](vector<int> &item) {
        std::for_each(item.begin(), item.end(), [&](const auto &item) {
            cout<<item<<" ";
        });
        cout<<"\n";
    });
    return 0;
}