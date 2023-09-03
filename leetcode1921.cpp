#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        int ans = 0;
        priority_queue<pair<int, int>> qu;
        for (int i = 0; i < dist.size(); i++) {
            int time = dist[i] / speed[i];
            if (dist[i] % speed[i] != 0)
                time++;
            qu.emplace(-time, i);
        }
        for (int j = 0; j < dist.size(); j++) {
            auto faq = qu.top();
            qu.pop();
            if (-faq.first <= j) {
                return j;
            }
        }
        return dist.size();
    }
};

int main() {
    vector<int> faq = {1, 3, 4};
    vector<int> qaq = {1, 1, 1};
    cout<<(new Solution)->eliminateMaximum(faq,qaq);
    return 0;
}