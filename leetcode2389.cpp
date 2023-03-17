#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size() - 1;
        int m = queries.size() - 1;
        vector<int> preSum(n + 2);
        std::sort(nums.begin(), nums.end());
        for (int i = 0;i <= n;i ++)
            preSum[i + 1] = preSum[i] + nums[i];
        for (int i = 0;i <= m;i ++)
            ans.push_back(upper_bound(preSum.begin(),preSum.end(),queries[i]) - preSum.begin() - 1);
        return ans;
    }
};
int main() {
    vector<int> qaq = {4,5,2,1};
    vector<int> faq=  {3,10,21};
    vector<int > ans = (new Solution)->answerQueries(qaq,faq);
    std::for_each(ans.begin(), ans.end(),[&](auto i) -> void {cout<<i<<endl;});
    return 0;
}