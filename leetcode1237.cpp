#include "bits/stdc++.h"
using namespace std;
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
class CustomFunction {
public:
    int f(int x, int y);
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int i = 1;i <= 1000;i ++) {
            if (customfunction.f(i,1) > z) {
                break;
            }
            int l = 1;
            int r = 1000;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (customfunction.f(i,mid) > z) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (customfunction.f(i,l - 1) == z) {
                ans.push_back({i,l - 1});
            }

        }
        return ans;
    }
};
int main() {
    return 0;
}