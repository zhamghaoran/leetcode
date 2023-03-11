#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
       unordered_map<int,int> mapp;
       int begin = -1;
       int maxxlen = 0;
       int sum = 0;
       mapp[0] = -1;
       for (int i = 0;i < array.size();i ++) {
           if (isalpha(array[i][0]))
               sum ++;
           else sum --;
           if (mapp.count(sum)) {
               int first = mapp[sum];
               if (i - first > maxxlen) {
                   maxxlen = i - first;
                   begin = first + 1;
               }
           } else
               mapp[sum] = i;
       }
       if (maxxlen == 0)
           return {};
       else
           return vector<string>(array.begin() + begin,array.begin() + maxxlen + begin);
    }
};
int main() {
    vector<string> faq = {"A","1"};
    vector<string> ans = (new Solution)->findLongestSubarray(faq);
    std::for_each(ans.begin(), ans.end(), [&](const auto &item) {
        cout<<item<<" ";
    });
    return 0;
}