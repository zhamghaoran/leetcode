#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    static bool pd(int i,int index,int n,int maxSum) {
        double ans1 = 0.00;
        if (i - index + 1 > 0)
            ans1 = 1.00 * (i - index + 1 + i) * 1.00 * (index) / 2.00;
        else {
            ans1 = 1.00 * (i + 1) * 1.00 * i / 2.00 + index - i;
        }
        double ans2 = 0.00;
        if (index < n) {
            if (i - n + index > 0)
                ans2 = (1.00 * (2 * i - n + index - 1) * 1.00 * (n - index) / 2.00);
            else
                ans2 = 1.00 * i * 1.00 *(i - 1) / 2.00 + n - index - i + 1;
        }
        return ans1 + ans2 <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        if (n == 1)
            return maxSum;
        index ++;
        int l = 1;
        int r = maxSum;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (pd(mid,index,n,maxSum)) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};
int main() {
    cout<<(new Solution)->maxValue(6,1,10);
    return 0;
}