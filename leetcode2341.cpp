#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> ans(2);
        int cnt = 0;
        for (int i = 1;i < nums.size();i ++) {
            if (nums[i] == nums[i - 1]) {
                cnt += 2;
                i ++;
            }
        }
        ans[0] = cnt / 2;
        ans[1] = nums.size() - cnt;
        return ans;
    }
};
int main() {
    return 0;
}