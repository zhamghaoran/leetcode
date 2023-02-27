#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int res = 0 ;
        vector<int> vis(nums.size(),0);
        for (int i = 0;i < nums.size();i ++) {
            if (!vis[i]) {
                int j = lower_bound(nums.begin(),nums.end(),nums[i] / 2) - nums.begin();
                while (j >= 0 && nums[j] > nums[i] / 2)
                    j --;
                while (j >= 0 && vis[j] == 1)
                    j --;
                if (j >= 0)
                    res ++,vis[j] = 1;
            }
        }
        return res * 2 ;
    }
};

int main() {
    vector<int> faq = {42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40};
    cout<<(new Solution)->maxNumOfMarkedIndices(faq);
    return 0;
}