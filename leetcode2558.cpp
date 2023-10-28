#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        long long ans = 0;
        priority_queue<int> heap(gifts.begin(),gifts.end());
        for (int i = 1;i <= k;i ++) {
            int faq = heap.top();
            heap.pop();
            faq = (int)sqrt(faq);
            cout<<faq<<endl;
            heap.push(faq);
        }
        while (!heap.empty()) ans += heap.top(),heap.pop();
        return ans;
    }
};

int main() {
    return 0;
}