#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<long long> faq;
        for (int i = 0; i < s.size(); i++) {
            long long tem = 0;
            for (int j = i; j < s.size() && j - i < 25; j++) {
                tem = tem << 1 | (s[j] - '0');
                faq.insert(tem);
            }
        }
        for (long long i = 1; i <= n; i++) {
            if (!faq.count(i))
                return false;
        }
        return true;
    }
};

int main() {
    cout<<(new Solution)->queryString("0110",4);
    return 0;

}