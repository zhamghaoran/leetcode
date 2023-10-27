#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        int ans = 0;
        int mod = 1000000007;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        int maxxH = 0;
        int maxxV = 0;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxxH = max(horizontalCuts[i] - horizontalCuts[i - 1], maxxH);
        }
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxxV = max(maxxV, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (long long) maxxH * (long long) maxxV % mod;
    }
};

int main() {
    return 0;
}