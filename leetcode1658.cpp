#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int minn = 0x3f3f3f3f;
        int l = -1;
        int r = 0;
        int a = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        int rsum = sum;
        for (int i = -1;i < a;i ++) {
            if (i != -1)
                lsum += nums[i];
            while (r <= nums.size() && lsum + rsum > x) {
                rsum -= nums[r];
                r ++;
            }
            if (lsum + rsum == x) {
                minn = min(minn ,i + 1 + a - r);
            }
        }
        return minn > a ? -1 : minn;
    }
};

int main() {
    vector<int> val = {1,1,4,2,3};
    cout<<(new Solution)->minOperations(val,5);
    return 0;
}