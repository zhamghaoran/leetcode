#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        int ans1 = nums[nums.size() - 1] - nums[0];
        int n = nums.size() - 1;
        int l1 = 1;
        int r1 = n - 1;
        while (l1 <= n && nums[l1] <= nums[0] + k) {
            l1++;
        }
        l1--;
        while (r1 >= 0 && nums[r1] + k >= nums[n]) {
            r1--;
        }
        r1++;
        for (int i = 0; i <= l1; i++) {
            for (int j = n; j >= r1; j--) {
                if (nums[i] + k > nums[j] - k) {
                    ans1 = min(ans1, nums[i] + k - nums[j] + k);
                } else {
                    ans1 = min(ans1, nums[j] - k - nums[i] - k);
                }
            }
        }
        return ans1;
    }
};

int main() {
    vector<int> a = {1, 3, 6};
    cout << (new Solution)->smallestRangeII(a, 3);
    return 0;
}