#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int> &nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                nums[i] *= 2, nums[i + 1] = 0;
        }
        int cnt = 0;
        for (int num : nums) {
            if (num)
                ans.push_back(num);
            else cnt++;
        }
        while (cnt)
            ans.push_back(0), cnt--;
        return ans;
    }
};

int main() {
    return 0;
}