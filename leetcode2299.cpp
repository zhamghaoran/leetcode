#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool a1 = false;
        bool a2 = false;
        bool a3 = false;
        bool a4 = false;
        bool a5 = true;
        if (password.size() < 8) {
            return false;
        }
        for (auto i: password) {
            if (i >= 'a' && i <= 'z')
                a1 = true;
            if (i >= 'A' && i <= 'Z')
                a2 = true;
            if (i >= '0' && i <= '9')
                a3 = true;
            if (i == '!' || i == '@' || i == '$' || i == '%' || i == '^' || i == '&' || i == '*' || i == '(' ||
                i == ')' || i == '-' || i == '+' || i == '#')
                a4 = true;
        }
        for (int i = 1; i < password.size(); i++) {
            if (password[i] == password[i - 1])
                a5 = false;
        }
        return a1 & a2 & a3 & a4 & a5;
    }
};

int main() {

    cout << (new Solution)->strongPasswordCheckerII("#Aa1a1a1");
    return 0;
}