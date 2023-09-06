#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                ans.push_back(s[i]);
            else {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}