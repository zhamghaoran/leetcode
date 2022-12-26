#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int res = 0;
        int j = 0;
        for (int i = 0;i < s.size();i ++) {
            j = 0;
            while (s[i] == s[i + j])
                j ++;
            res += (1 + j) * j / 2;
            res %= mod;
            i = i + j - 1;
        }
        return res;
    }
};
int main() {
    string s = "xy";
    cout<<(new Solution)->countHomogenous(s);
    return 0;
}