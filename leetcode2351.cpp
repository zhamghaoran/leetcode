#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> faq;
        for (auto i : s) {
            if (faq[i])
                return i;
            else
                faq[i] = 1;
        }
        return 'a';
    }
};
int main() {
    return 0;
}