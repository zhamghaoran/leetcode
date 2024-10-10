#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> tem = nums;
        std::sort(tem.begin(), tem.end());
        int l = 0;
        int r = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != tem[i]) {
                break;
            }
            l++;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != tem[i]) {
                break;
            }
            r--;
        }
        return max(r - l + 1, 0);
    }
};

int main() {
    return 0;
}