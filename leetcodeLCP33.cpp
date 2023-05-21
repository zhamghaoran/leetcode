#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int storeWater(vector<int> &bucket, vector<int> &vat) {
        int ans = 0x3f3f3f3f;
        int maxx = 0;
        std::for_each(vat.begin(), vat.end(), [&](const auto &item) {
           maxx = max(maxx,item);
        });
        for (int i = 1;i <= maxx;i ++) {
            int sum = 0;
            for (int j = 0;j < bucket.size();j ++) {
                int should  = vat[j] / i;
                if (vat[j] % i)
                    should ++;
                sum += max(0,should - bucket[j]);
            }
            ans = min(i + sum,ans);
        }
        if (ans == 0x3f3f3f3f)
            ans  = 0;
        return ans;
    }

};

int main() {
    vector<int> faq = {1, 3};
    vector<int> qaq = {6, 8};
    cout<<(new Solution)->storeWater(faq,qaq);
    return 0;
}