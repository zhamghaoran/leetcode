#include  "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0;
//        if (nums.size() == 1) {
//            if (nums[0] == k) {
//                return 1;
//            } else {
//                return 0;
//            }
//        }
        vector<int> res(nums.size() + 1, 0);
        int tem = 0;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = tem;
            tem += nums[i];
        }
        res[nums.size()] = tem;
        unordered_map<int, int> sum;
        for (int i = 0; i <= nums.size(); i++) {
            ans += sum[res[i] - k];
            sum[res[i]] += 1;
        }
        return ans;
    }
};

int main() {
    vector<int> faq = {1};
    cout << (new Solution)->subarraySum(faq, 0);
    return 0;
}