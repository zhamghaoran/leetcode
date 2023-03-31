#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int ans = 0;
        for (  int i = 0; i < nums.size(); i++) {
            for ( int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - nums[i] == diff) {
                    int z = lower_bound(nums.begin(), nums.end(), nums[j] + diff) - nums.begin();
                    if (z < nums.size() && z != -1 && nums[z] - nums[j] == diff)
                        ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> faq = {1, 5, 6, 9};
    cout << (new Solution)->arithmeticTriplets(faq, 2);
    return 0;
}