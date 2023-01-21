#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static constexpr int inf = 0x3f3f3f3f;

    int minSideJumps(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<int> d = {1, 0, 1};
        for (int i = 1; i <= n; i++) {
            int minCnt = inf;
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                } else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};

int main() {
    vector<int> faq = {0, 2, 2, 1, 0, 3, 0, 3, 0, 1, 0};
    cout << (new Solution)->minSideJumps(faq);
    return 0;
}