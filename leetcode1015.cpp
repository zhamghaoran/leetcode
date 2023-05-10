#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int re = 1 % k;
        int len = 1;
        unordered_set<int> faq;
        faq.insert(re);
        while (re != 0) {
            re = (re * 10 + 1) % k;
            len ++;
            if (!faq.count(re))
                faq.insert(re);
            else
                return -1;
        }
        return len;
    }
};

int main() {
    cout << (new Solution)->smallestRepunitDivByK(11);
    return 0;
}