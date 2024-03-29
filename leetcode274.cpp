#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

int main() {
    vector<int> faq = {11,15};
    cout << (new Solution)->hIndex(faq);
    return 0;
}