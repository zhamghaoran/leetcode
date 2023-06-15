#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    vector<vector<int>> faq;

    bool pd(int be, int end, int k) {
        int mk = end - be + 1 & 1;
        int cnt = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            if ((faq[end + 1][i] - faq[be][i] & 1))
                cnt++;
        }
        return (cnt + 1) / 2 - mk - k <= 0;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
        faq = vector<vector<int>>(s.size() + 10, vector<int>(130));
        vector<bool> ans;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                faq[i + 1][j] = faq[i][j];
            }
            faq[i + 1][s[i]]++;
        }
        for (auto &querie: queries) {
            ans.push_back(pd(querie[0], querie[1], querie[2]));
        }
        return ans;
    }
};

int main() {
    string s = "dgt";
    vector<vector<int>> qaq = {{0, 2, 0}};
    vector<bool> ans = (new Solution)->canMakePaliQueries(s, qaq);
    std::for_each(ans.begin(), ans.end(), [&](bool faq) -> void { cout << faq << endl; });
    return 0;
}