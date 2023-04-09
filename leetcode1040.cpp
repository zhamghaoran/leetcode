#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &stones) {
        vector<int> ans;
        std::sort(stones.begin(), stones.end());
        vector<int> lian;
        int len = 1;
        for (int i = 0; i < stones.size() - 1; i++) {
            if (stones[i] == stones[i + 1] - 1)
                len++;
            else {
                lian.push_back(len);
                len = 1;
            }
        }
        int minn = 0;
        int maxx = 0;
        int sum = 0;
        for (int i = 0; i < lian.size() - 1; i++) {
            sum += lian[i];
            int cha = stones[sum] - stones[sum - 1];
            maxx += max(cha, max(lian[i], lian[i - 1]));
            minn += min(cha, min(lian[i], lian[i - 1]));
        }
        ans.push_back(minn);
        ans.push_back(maxx);
        return ans;
    }
};

int main() {

    return 0;
}