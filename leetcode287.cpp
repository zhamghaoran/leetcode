#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main() {
    vector<int> res = {1,3,4,2,2};
    cout << (new Solution)->findDuplicate(res);
    return 0;
}