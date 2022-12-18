#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums, int k) {
        vector<long long> faq(100010, 0);
        long long cnt = 1;
        for (long long i = 0; i < nums.size(); i++) {
            if (nums[i])
                faq[cnt++] = i + 1;
        }
        vector<long long> sum(100010, 0);
        for (long long i = 1; i <= cnt - 1; i++) {
            sum[i] = sum[i - 1] + faq[i];
        }
        long long ans = 0x3f3f3f3f;
        long long jian = (k / 2) * (1 + k / 2);
        for (long long i = k; i <= cnt - 1; i++) {
            long long qaq = 0;
            long long mid = i - k / 2;
            qaq = sum[i] - sum[mid] - (sum[mid - 1] - sum[i - k]);
            if (!(k & 1))
                qaq -= faq[mid];
            ans = min(ans, qaq);
        }
        if (!(k & 1))
            jian -= k / 2;
        return ans - jian;
    }

};

signed main() {
    vector<long long> qaq = {1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << (new Solution)->minMoves(qaq, 7);
}