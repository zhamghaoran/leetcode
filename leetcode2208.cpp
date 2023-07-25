#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        priority_queue<double> faq;
        double sum = 0.00;
        std::for_each(nums.begin(), nums.end(), [&](int x) -> void {
            sum += x;
            faq.push(x);
        });
        double jian = 0.00;
        for (int i = 1; i; i++) {
            double x = faq.top();
            faq.pop();
            jian +=  x / 2.00;
            if (jian >= sum / 2.00)  {
                return i;
            } else {
                faq.push(x / 2.00);
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}