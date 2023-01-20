#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        vector<int> ans(k);
        std::sort(logs.begin(), logs.end(), [&](auto a, auto b) -> bool {
            return a[0] < b[0];
        });
        int cnt = 0;
        vector<vector<int>> neww;
        neww.push_back(vector<int>{0, logs[0][1]});
        for (int i = 1; i < logs.size(); i++) {
            if (logs[i][0] == logs[i - 1][0]) {
                neww.push_back(vector<int>{cnt, logs[i][1]});
            } else {
                neww.push_back(vector<int>{++cnt, logs[i][1]});
            }
        }
        for (int i = 0; i < neww.size(); i++) {
            cnt = 0;
            set<int> calc;
            calc.insert(neww[i][1]);
            while (i + cnt < neww.size() && neww[i + cnt][0] == neww[i][0]) {
                calc.insert(neww[i + cnt][1]);
                cnt++;
            }
            ans[calc.size() - 1]++;
            i += (cnt - 1);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> faq = {{0, 5},
                               {1, 2},
                               {0, 2},
                               {0, 5},
                               {1, 3}};
    vector<int> ans = (new Solution)->findingUsersActiveMinutes(faq,5);
    std::for_each(ans.begin(), ans.end(), [&](const auto &item) {
        cout<<item<<endl;
    });
    return 0;
}