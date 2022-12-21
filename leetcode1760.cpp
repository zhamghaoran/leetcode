#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = 0;
        int l = 1;
        std::for_each(nums.begin(), nums.end(), [&](const auto &item) {
            r = max(r,item);
        });
        auto pd = [&](int mid) -> bool {
            int ans = 0;
            std::for_each(nums.begin(),nums.end(),[&](const auto & item) -> void {
                ans += (item - 1) / mid;
            });
            return ans <= maxOperations;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (pd(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};
int main() {
    vector<int> faq = {4,412,354,607,587,28,136,327,929,905,671,811,572,152,556,96,205,188,505,14,602,591,802,662,543,781,878,812,539,981,587,716,531,354,92,165,352,522,983,966,378,911,873,606,392,927,426,726,892,939,96,419,769,387,178,895,41,291,437,513,37,569,945,102,460};
    cout<<(new Solution)->minimumSize(faq,33);
}