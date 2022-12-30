#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        vector<int> faq;
        std::sort(nums1.begin(), nums1.end());
        auto it = std::unique(nums1.begin(), nums1.end());
        nums1.erase(it,nums1.end());
        std::sort(nums2.begin(), nums2.end());
        nums2.erase(std::unique(nums2.begin(), nums2.end()),nums2.end());
        std::sort(nums3.begin(), nums3.end());
        nums3.erase(std::unique(nums3.begin(), nums3.end()),nums3.end());
        std::for_each(nums1.begin(), nums1.end(), [&](const auto &item) {
            faq.push_back(item);
        });
        std::for_each(nums2.begin(), nums2.end(), [&](const auto &item) {
            faq.push_back(item);
        });
        std::for_each(nums3.begin(), nums3.end(), [&](const auto &item) {
            faq.push_back(item);
        });
        std::sort(faq.begin(), faq.end());
        vector<int> ans;
        for (int i = 0; i < faq.size(); i++) {
            bool qaq = false;
            while (i + 1 < faq.size() && faq[i] == faq[i + 1]) qaq = true, i++;
            if (qaq)
                ans.push_back(faq[i - 1]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 1, 3, 2};
    vector<int> nums2 = {2, 3};
    vector<int> nnums3 = {3};
    vector<int> ans = (new Solution)->twoOutOfThree(nums1,nums2,nnums3);
    for (const auto &item: ans) cout<< item<<endl;
    return 0;
}