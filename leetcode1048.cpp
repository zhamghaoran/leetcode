#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        int ans = 0;
        vector<int> dp(1010, 1);
        std::sort(words.begin(), words.end(), [&](string a, string b) -> bool {
            if (a.size() == b.size())
                return a < b;
            else return a.size() < b.size();
        });
        auto pd = [&](int i, int j) -> bool {
            string a1 = words[i];
            string b2 = words[j];
            int ii = 0;
            for (; ii < a1.size(); ii++) {
                if (a1[ii] != b2[ii]) {
                    break;
                }
            }
            b2.insert(ii, string(1, a1[ii]));
            return a1 == b2;
        };
        for (int i = 0; i < words.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (words[i].length() - words[j].length() > 1)
                    break;
                if (words[i].length() - words[j].length() == 1 && pd(i, j))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    vector<string> val = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << (new Solution)->longestStrChain(val);
    return 0;
}