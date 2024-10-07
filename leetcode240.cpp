#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowNum;
        for (int i = 0; i < n; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                rowNum.push_back(i);
            }
        }
        for (int i = 0; i < rowNum.size(); i++) {
            if (find(matrix[rowNum[i]], target)) {
                return true;
            }
        }
        return false;
    }

    bool find(vector<int> nums, int tar) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (tar == nums[mid]) {
                return true;
            }
            if (tar > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l] == tar;
    }
};

int main() {

    return 0;
}