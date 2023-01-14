#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int ans = 0;
        int maxx = 0;
        std::for_each(nums.begin(), nums.end(), [&](const auto &item) {
            maxx = max(maxx,item);
        });
        vector<bool> vis(maxx + 1);
        for (auto i : nums) {
            vis[i] = true;
        }
        for (int i = 1;i <= maxx;i ++) {
            int gcd = 0;
            for (int j = i;j <= maxx;j += i) {
                if (vis[j]) {
                    if (gcd == 0){
                        gcd = j;
                    } else {
                        gcd = __gcd(gcd,j);
                    }
                    if (gcd == i) {
                        ans ++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> faq = {16,15};
    cout<<(new Solution)->countDifferentSubsequenceGCDs(faq);
    return 0;
}