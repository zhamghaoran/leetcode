#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ans;
        std::sort(intervals.begin(), intervals.end(), [&](const vector<int> a, const vector<int> b) -> bool {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int l = intervals[0][0];
        int r = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > r) {
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            } else {
                r = max(r, intervals[i][1]);
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};

int main() {

    return 0;
}