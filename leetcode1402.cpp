#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int> &satisfaction) {
        int ans = 0;
        vector<int> faq;
        std::sort(satisfaction.begin(), satisfaction.end());
        int begin = lower_bound(satisfaction.begin(), satisfaction.end(), 0) - satisfaction.begin();
        int sum = 0;
        for (int i = begin; i < satisfaction.size(); i++) {
            sum += satisfaction[i];
            ans += (i - begin + 1) * satisfaction[i];
        }
        begin--;
        while (begin >= 0) {
            if (ans + satisfaction[begin] + sum >= ans) {
                ans = ans + satisfaction[begin] + sum;
                sum += satisfaction[begin];
                begin--;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}