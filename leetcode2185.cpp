#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int len = pref.size();
        for (auto i : words)
            if (i.size() >= len && i.substr(0,len) == pref)
                ans ++;
        return ans;
    }
};
int main() {
    return 0;
}