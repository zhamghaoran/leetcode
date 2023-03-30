#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        int ans = 0;
        sort(points.begin(),points.end(),[&](vector<int> a,vector<int> b) -> bool {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        for (int i = 0;i < points.size() - 1;i ++) {
            ans = max(ans,points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};
int main() {
    return 0;
}