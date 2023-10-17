#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        long long ans = 0;
        priority_queue<long long> faq(nums.begin(), nums.end());
        for (int i = 1; i <= k; i++) {
            ans += faq.top();
            long long x = faq.top();
            x = ceil(1.00 * x / 3);
            faq.pop();
            faq.push(x);
        }
        return ans;
    }
};

int main() {
    return 0;
}