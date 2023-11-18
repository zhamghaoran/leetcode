#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        map<int, int> faq;
        int ans = -1;
        for (int i: nums) {
            int sum = weisum(i);
            if (!faq.count(sum)) {
                faq[sum] = i;
            } else {
                ans = max(ans, faq[sum] + i);
                faq[sum] = max(faq[sum], i);
            }
        }
        return ans;
    }

    int weisum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};

int main() {
    return 0;
}