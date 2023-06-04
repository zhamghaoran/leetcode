#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> ans;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            ans.insert(1.00 * (nums[i ++] + nums[j --]) / 2);
        }
        return ans.size();
    }
};
int main() {
    return 0;
}