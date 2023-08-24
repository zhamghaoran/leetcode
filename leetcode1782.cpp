#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries) {
        unordered_map<int, int> mapp;
        vector<int> de(n, 0);
        std::for_each(edges.begin(), edges.end(), [&](const vector<int> &qaq) -> void {
            de[qaq[0] - 1]++;
            de[qaq[1] - 1]++;
            mapp[min(qaq[0], qaq[1]) * (n + 1) + max(qaq[0], qaq[1])]++;
        });
        vector<int> anss;
        vector<int> faq = de;
        std::sort(de.begin(), de.end());
        std::for_each(queries.begin(), queries.end(), [&](const int i) -> void {
            int ans = 0;
            for (int j = 0; j < n; j++) {
                int x = upper_bound(de.begin() + j + 1, de.end(), i - de[j]) - de.begin();
                ans += n - x;
            }
            for (auto &[k, v]: mapp) {
                int xx = k / (n + 1) - 1;
                int yy = k % (n + 1) - 1;
                if (faq[xx] + faq[yy] > i && faq[xx] + faq[yy] - v <= i) {
                    ans--;
                }
            }
            anss.push_back(ans);
        });
        return anss;
    }
};

int main() {
    vector<vector<int>> faq = {{1, 2},
                               {2, 4},
                               {1, 3},
                               {2, 3},
                               {2, 1}};
    vector<int> qaq = {2, 3};
    vector<int> ans = (new Solution)->countPairs(4, faq, qaq);
    for (auto i: ans)
        cout << i << endl;
    return 0;
}