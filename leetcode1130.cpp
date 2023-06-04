#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        long long ans = 0;
        int nowMax = arr[0];
        for (int i = 1;i < arr.size();i ++) {
            ans += arr[i] * nowMax;
            nowMax = max(nowMax,arr[i]);
        }
        long long maxx = ans;
        std::reverse(arr.begin(), arr.end());
        nowMax = arr[0];
        ans = 0;
        for (int i = 1;i < arr.size();i ++) {
            ans += arr[i] * nowMax;
            nowMax = max(nowMax,arr[i]);
        }
        return min(ans,maxx);
    }
};
int main() {

    return 0;
}