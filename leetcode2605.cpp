#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        set<int> faq(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        for (auto i: nums2) {
            if (faq.count(i)) {
                return i;
            }
        }
        int minn1, minn2 = 0x3f3f3f3f;
        for (auto i: nums1) {
            minn1 = min(minn1, i);
        }
        for (auto i: nums2) {
            minn2 = min(minn2, i);
        }
        return min(minn1, minn2) * 10 + max(minn1, minn2);
    }
};

int main() {
    return 0;
}