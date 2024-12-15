#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        for (int i = 1; i <= k; i++) {
            int pos = getMinPos(nums);
            nums[pos] *= multiplier;
        }
        return nums;
    }

    int getMinPos(vector<int> vals) {
        int pos = -1;
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < vals.size(); i++) {
            if (vals[i] < minn) {
                minn = vals[i];
                pos = i;
            }
        }
        return pos;
    }
};

int main() {

    int j = 0;
    for (int i = 0;i < 100;i ++) {
        j = j ++;
    }
    cout<<j;
    return 0;
}