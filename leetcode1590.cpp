#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int sum[100010];
        ::memset(sum, 0, sizeof sum);
        unordered_map<int, int> faq;
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
            sum[i + 1] %= p;
        }
        if (sum[nums.size()] % p == 0)
            return 0;
        int x = sum[nums.size()] % p;
        int minn = nums.size();
        for (int i = 0; i <= nums.size(); i++) {
            faq[sum[i]] = i;
            int qaq = (sum[i] - x + p) % p;
            auto xx = faq.find(qaq);
            if (xx != faq.end())
                minn = min(minn,i - xx->second);
        }
        if (minn == nums.size())
            return -1;
        else
            return minn;
    }
};

int main() {
    vector<int> faq = {3, 1, 4, 2};
    cout << (new Solution)->minSubarray(faq, 6);
    return 0;
}