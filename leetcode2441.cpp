#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaxK(vector<int> &nums) {
        unordered_set<int> faq;
        int maxx = 0;
        std::for_each(nums.begin(), nums.end(), [&](const int a) -> void {
           if (faq.count(-a))
               maxx = max(maxx, abs(a));
           else
               faq.insert(a);
        });
        return maxx;
    }
};

int main() {
    return 0;
}