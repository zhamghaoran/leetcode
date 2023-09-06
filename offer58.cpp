#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans(s.begin() + n, s.end());
        for (int i = 0; i < n; i++) ans.push_back(s[i]);
        return ans;
    }
};

int main() {

    return 0;
}