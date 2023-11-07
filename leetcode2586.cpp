#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char yuan[5]{'a', 'e', 'i', 'o', 'u'};

    int vowelStrings(vector<string> &words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (pd(words[i]))
                ans++;
        }
        return ans;
    }

    bool pd(string s) {
        int ans = 0;
        for (char i: yuan) {
            if (s[0] == i) {
                ans++;
                break;
            }
        }
        for (char i: yuan) {
            if (s[s.size() - 1] == i) {
                ans++;
                break;
            }
        }
        return ans == 2;
    }
};

int main() {
    return 0;
}