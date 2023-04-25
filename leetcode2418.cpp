#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        vector<pair<int, string> > val;
        for (int i = 0; i < heights.size(); i++)
            val.emplace_back(heights[i], names[i]);
        std::sort(val.begin(), val.end(), [&](pair<int, string> a, pair<int, string> b) -> bool {
            return a.first > b.first;
        });
        vector<string> ans;
        std::for_each(val.begin(), val.end(), [&](pair<int, string> a) -> void {
            ans.push_back(a.second);
        });
        return ans;
    }
};

int main() {
    return 0;
}