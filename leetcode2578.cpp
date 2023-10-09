#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        vector<int> faq;
        while (num) {
            faq.push_back(num % 10);
            num /= 10;
        }
        sort(faq.begin(), faq.end());
        int ans = 0;
        int a1 = faq[0];
        int a2 = faq[1];
        if (faq.size() < 2) {
            return faq[0];
        }
        for (int i = 2; i < faq.size(); i++) {
            if (i % 2 == 0)
                a1 = a1 * 10 + faq[i];
            else
                a2 = a2 * 10 + faq[i];
        }
        return a1 + a2;
    }
};
int main() {

    return 0;
}