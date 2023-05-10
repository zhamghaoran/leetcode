#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        vector<pair<int, int>> pre;
        vector<pair<int, int>> aft;
        int num = std::upper_bound(fruits.begin(), fruits.end(), startPos, [&](int a, vector<int> b) -> bool {
            return b[0] > a;
        }) - fruits.begin();
        if (num > 0) {
            pre.emplace_back(startPos - fruits[num - 1][0] - 1,0);
        }


        cout<<num;
    }
};

int main() {
    return 0;
}