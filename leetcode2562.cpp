#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int> &nums) {
        long long ans = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            if (i != j)
                ans += add(nums[i++], nums[j--]);
            else ans += nums[i],i ++;
        }
        return ans;
    }

    long long add(int x, int y) {
        long long ans = x;
        vector<int> faq;
        while (y) {
            faq.push_back(y % 10);
            y /= 10;
        }
        for (int i = faq.size() - 1;i >= 0;i --) {
            ans = ans * 10 + faq[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}