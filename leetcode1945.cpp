#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        string qaq;
        int ans = 0;
        for (auto i : s)
            qaq.append(to_string(i - 'a' + 1));
        for (int i = 1;i <= k;i ++) {
            ans = 0;
            for (auto j : qaq) {
                ans += j - '0';
            }
            qaq = to_string(ans);
        }
        return ans;
    }
};
int main() {
    cout<<(new Solution)->getLucky("leetcode",2);
    return 0;
}