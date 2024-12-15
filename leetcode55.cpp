#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int maxx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxx) {
                break;
            } else {
                maxx = max(maxx, i + nums[i]);
            }
        }
        return maxx >= nums.size() - 1;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    (new Solution)->canJump(nums);
    return 0;
}