#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums[0] == 1;
        }
        int gcd = __gcd(nums[0],nums[1]);
        for (int i = 2;i < nums.size();i ++) {
            gcd = __gcd(gcd,nums[i]);
        }
        return gcd != 1;
    }
};
int main() {
    return 0;
}