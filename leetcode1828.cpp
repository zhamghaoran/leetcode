#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    static double calc(int x1,int y1,int x2,int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        std::for_each(queries.begin(), queries.end(), [&](const auto &item) {
            int qaq = 0;
            std::for_each(points.begin(), points.end(),[&](const auto &j) -> void {
                if (calc(j[0],j[1],item[0],item[1]) <= item[2])
                    qaq ++;
            });
            ans.push_back(qaq);
        });
        return ans;
    }
};
int main() {
    return 0;
}