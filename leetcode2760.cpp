#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= threshold && nums[i] % 2 == 0) dp[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > threshold) {
                continue;
            }
            if (nums[i] % 2 != nums[i + 1] % 2 && nums[i + 1] <= threshold) {
                dp[i + 1] = dp[i] + 1;
                ans = max(ans, dp[i + 1]);
            } else if (nums[i] % 2 == 0) dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        if (nums[nums.size() - 1] % 2 == 0 && nums[nums.size() - 1] <= threshold) ans = max(ans, dp[nums.size() - 1]);
        return ans;
    }

    // 栈里面维护两个信息 大小和下标
    // 当这个数字被弹出的时候就代表找到了一个最近的比他大的数字，两个下标相减就是答案
    vector<int> tem(vector<int> &deily) {
        stack<char> qaq;
        vector<int> ans(deily.size(), 0);
        stack<pair<int, int>> sta;
        for (int i = 0; i < deily.size(); i++) {
            if (sta.empty())
                 sta.push(make_pair(deily[i], i));
            else {
                while (!sta.empty() && deily[i] > sta.top().first) {
                    int num = sta.top().second;
                    ans[num] = i - num;
                    sta.pop();
                }
                sta.push(make_pair(deily[i], i));
            }
        }
        return ans;
    }
};

int main() {
    vector<int> faq{3,1,4};
    vector<int> ans = (new Solution)->tem(faq);
    std::for_each(ans.begin(), ans.end(), [&](auto a) -> void{
        cout << a << endl;
    });
    return 0;
}