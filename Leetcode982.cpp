#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &nums) {
         vector<int> cnt ((1 << 16) + 1);
         for (int i = 0;i < nums.size();i ++) {
             for (int j = 0;j < nums.size();j ++) {
                 cnt[nums[i] & nums[j]] ++;
             }
         }
         int ans = 0;
         for (int i = 0;i <= (1 << 16);i ++) {
             for (int num : nums) {
                 if ((num & i) == 0)
                     ans += cnt[i];
             }
         }
        return ans;
    }

};

int main() {
    vector<int> faq = {2, 1, 3};
    cout << (new Solution)->countTriplets(faq);
    return 0;
}