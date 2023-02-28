#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        vector<vector<int>> ans;
        std::for_each(items2.begin(), items2.end(), [&](const auto &item) {
            items1.push_back(item);
        });
        std::sort(items1.begin(), items1.end(), [&](vector<int> a, vector<int> b) -> bool {
            return a[0] < b[0];
        });
        for (int i = 0; i < items1.size(); i++) {
            vector<int> qaq;
            qaq.push_back(items1[i][0]);
            int sum = 0;
            int cnt = 0;
            while (i + cnt < items1.size() && items1[i][0] == items1[i + cnt][0]) {
                sum += items1[i + cnt][1];
                cnt ++;
            }
            qaq.push_back(sum);
            ans.push_back(qaq);
            i = i + cnt - 1;
        }
        return ans;
    }
};

int main() {
    return 0;
}