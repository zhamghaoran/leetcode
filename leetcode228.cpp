#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;
        int be = 0;
        if (nums.empty())
            return ans;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] != nums[i] + 1) {
                if (be == i) {
                    ans.push_back(to_string(nums[i]));
                } else {
                    ans.push_back(to_string(nums[be]) + "->" + to_string(nums[i]));
                }
                be = i + 1;
            }
        }
        if (be == nums.size() - 1) {
            ans.push_back(to_string(nums[be]));
        } else {
            ans.push_back(to_string(nums[be]) + "->" + to_string(nums[nums.size() - 1]));
        }
        return ans;
    }
};

int main() {

    return 0;
}