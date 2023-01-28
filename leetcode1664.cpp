#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        if (nums.size() <= 1)
            return 1;
        int ans = 0;
        int a = nums.size() - 1;
        vector<int> ji(a + 1,0);
        vector<int> ou(a + 1, 0);
        ou[1] = ou[0] = nums[0];
        ji[1] = nums[1];
        for (int i = 2;i <= a;i ++) {
            if (i % 2 == 1) {
                ji[i] = ji[i - 1] + nums[i];
                ou[i] = ou[i - 1];
            } else {
                ou[i] = ou[i - 1] + nums[i];
                ji[i] = ji[i - 1];
            }
        }
        for (int i = 0;i <= a;i ++) {
            if (i > 0){
                if (ji[i - 1] + ou[a] - ou[i] == ou[i - 1] + ji[a] - ji[i])
                    ans ++;
            } else {
                if (ou[a] - ou[i] == ji[a] - ji[i])
                    ans ++;
            }
        }
        return ans;
    }
};
int main () {
    vector<int> val = {1};
    cout<<(new Solution)->waysToMakeFair(val);
    return 0;
}