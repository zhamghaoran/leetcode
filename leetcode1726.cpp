#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        int ans = 0;
        for (int i = 0;i < nums.size();i ++) {
            for (int j = i + 1;j < nums.size();j ++) {
                for (int k = j + 1;k < nums.size();k ++) {
                    for (int z = k + 1;z < nums.size();z ++) {
                        if (nums[i] * nums[j] == nums[k] * nums[z] || nums[i] * nums[k] == nums[j] * nums[z] || nums[i] * nums[z] == nums[j] * nums[k]) {
                            ans ++;
                        }
                    }
                }
            }
        }
        return ans * 8;
    }
};

int main() {
    return 0;
}