#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        int ans = logs[0][0];
        int maxx = logs[0][1];
        for (int i = 1; i < logs.size(); i++) {
            if (logs[i][1] - logs[i - 1][1] > maxx) {
                maxx = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            } else if (logs[i][1] - logs[i - 1][1] == maxx) ans = min(ans, logs[i][0]);
        }
        return ans;
    }
};

int main() {
    return 0;
}