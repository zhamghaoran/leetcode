#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int ans = 0;
        vector<int> val(nums.size() + 1,0);
        for (int i = 0;i < nums.size();i ++) {
            val[i + 1] = val[i] + nums[i];
        }
        for (int i = firstLen;i <= nums.size();i ++) {
            int tem = val[i] - val[i - firstLen];
            for (int j = i + secondLen;j <= nums.size();j ++) {
                ans = max(ans,tem + val[j] - val[j - secondLen]);
            }
        }
        for (int i = secondLen;i <= nums.size();i ++) {
            int tem = val[i] - val[i - secondLen];
            for (int j = i + firstLen;j <= nums.size();j ++) {
                ans = max(ans,tem + val[j] - val[j - firstLen]);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> val = {0,6,5,2,2,5,1,9,4};
    cout<<(new Solution)->maxSumTwoNoOverlap(val,1,2);
    return 0;
}