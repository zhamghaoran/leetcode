#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i = 0;i < s.size();i ++) {
            for (int j  = 0;j < t.size();j ++) {
                int k = 0;
                int dif = 0;
                while (i + k < s.size() && j + k < t.size()) {
                    if (s[i + k] != t[j + k]) {
                        dif ++;
                    }
                    if (dif == 1)
                        ans ++;
                    if (dif > 1)
                        break;
                    k ++;
                }
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}