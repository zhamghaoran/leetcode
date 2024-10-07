#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else {
                sta.pop();
                if (sta.empty()) {
                    sta.push(i);
                } else {
                    ans = max(ans, i - sta.top());
                }
            }
        }
        return ans;
    }
};

int main() {
   cout<< (new Solution)->longestValidParentheses(")()())");
    return 0;
}