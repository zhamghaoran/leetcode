#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int begin = std::find(nums.begin(), nums.end(),k) - nums.begin();
        unordered_map<int,int> count;
        int sum = 0;
        count[0] = 1;
        int ans = 0;
        for (int i = 0;i < nums.size();i ++) {
            if (nums[i] > k)
                sum ++;
            else if(nums[i] < k)
                sum --;
            if (i < begin)
                count[sum] ++;
            else {
                ans += count[sum];
                ans += count[sum - 1];
            }
        }
        return ans;
    }
};
int main() {
        vector<int> faq=  {2,3,1,3};
    cout<<(new Solution)->countSubarrays(faq,2);
    return 0;
}