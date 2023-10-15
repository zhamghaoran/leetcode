#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++) {
            mapp[nums[i]]++;
        }
        for (auto [k, v]: mapp) {
            if (v == 1) {
                return k;
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}