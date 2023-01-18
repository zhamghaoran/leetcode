#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        int res = 0;
        unordered_map<int, int> h;
        for (int i : nums) {
            int temp = i, j = 0;
            while (temp > 0) {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            res = (res + h[i - j]) % MOD;
            h[i - j]++;
        }
        return res;
    }
};
int main() {
    vector<int> val = {442111244, 357716602, 131050131, 251794140, 4046404, 373969224, 1082801, 468525864, 384140537,492968345};
    cout << (new Solution)->countNicePairs(val);
    return 0;
}