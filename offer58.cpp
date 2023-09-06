#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans(s.begin() + n, s.end());
        return ans.append(s.begin(),s.begin() + n);
    }
};

int main() {

    return 0;
}