#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> tree;
    int maxx;

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int val) {
        for (; x <= maxx; x += lowbit(x))
            tree[x] = max(tree[x], val);
    }

    int get(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x))
            ans = max(ans, tree[x]);
        return ans;
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int ans;
        std::for_each(scores.begin(), scores.end(), [&](const auto &item) {
            maxx = max(maxx, item);
        });

        tree = vector<int>(maxx + 10, 0);
        vector<pair<int, int>> faq;
        for (int i = 0; i < scores.size(); i++)
            faq.emplace_back(scores[i], ages[i]);

        std::sort(faq.begin(), faq.end(), [&](pair<int, int> x, pair<int, int> y) -> bool {
            if (x.second == y.second)
                return x.first < y.first;
            return x.second < y.second;
        });

        update(faq[0].first, faq[0].first);
        ans = faq[0].first;

        for (int i = 1; i < faq.size(); i++) {
            int qaq = get(faq[i].first);
            update(faq[i].first, qaq + faq[i].first);
            ans = max(qaq + faq[i].first, ans);
        }
        return ans;
    }
};

int main() {
    vector<int> score = {1,2,3,5};
    vector<int> age = {8,9,10,1};
    cout << (new Solution)->bestTeamScore(score, age);
    return 0;
}