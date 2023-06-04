#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> a(words.size() + 1,0);
        vector<int> e(words.size() + 1,0);
        vector<int> ii(words.size() + 1,0);
        vector<int> o(words.size() + 1,0);
        vector<int> u(words.size() + 1,0);
        for (int i = 0;i < words.size();i ++) {
            a[i + 1] = a[i];
            e[i + 1] = e[i];
            ii[i + 1] = ii[i];
            o[i + 1] = o[i];
            if (words[i] == "a") {
                a[i + 1] ++;
            } else if (words[i] == "e") {
                e[i + 1] ++;
            } else if (words[i] == "i") {
                ii[i + 1] ++;
            } else if (words[i] == "o") {
                o[i + 1] ++;
            } else if (words[i] == "u") {
                u[i + 1] ++;
            }
        }

    }
};
int main() {
    return 0;
}