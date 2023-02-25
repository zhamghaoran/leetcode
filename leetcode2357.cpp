#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        int sum = 0;
        std::for_each(nums.begin(), prev(nums.end()), [&](const auto &item) {
            if (nums[nums.size() - 1] && item - sum > 0)
                nums[nums.size() - 1] -= (item - sum),cnt ++,sum += (item - sum);
            if (!nums[nums.size() - 1])
                return ;
        });
        if (nums[nums.size() - 1])
            cnt ++;
        return cnt;
    }
};

int main() {
    vector<int> faq = {1,5,0,3,5};
    cout << (new Solution)->minimumOperations(faq);
    return 0;
}