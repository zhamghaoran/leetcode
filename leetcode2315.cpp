#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool faq = false;
        for (char i : s) {
            if (i == '|')
                faq = !faq;
            if (i == '*' && !faq)
                ans ++;
        }
        return ans;
    }
};
int main() {
    return 0;
}