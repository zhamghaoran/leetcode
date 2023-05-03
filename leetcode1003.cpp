#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        while (s.find("abc") != string::npos) {
            string sub = "abc";
            string rep;
            size_t pos = 0;
            while ((pos = s.find(sub, pos)) != string::npos) {
                s.replace(pos, sub.length(), rep);
                pos += rep.length();
            }
        }
        return s.empty();
    }
};

int main() {
    cout<<(new Solution)->isValid("abcabcababcc");
    return 0;
}