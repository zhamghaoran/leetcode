#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int,int> faq;
        for (int num : nums) {
            faq[num] ++;
        }
        vector<int> ans;
        for (auto [k,v] : faq) {
            if (v == 1) ans.push_back(k);
        }
        return ans;
    }
};

int main() {
    return 0;
}