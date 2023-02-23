#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        for (int i = 0;i < ans.size();i ++) {
            ans[i] = (i >> 1) ^ start ^ i;
        }
        return ans;
    }
};
int main() {

    return 0;
}