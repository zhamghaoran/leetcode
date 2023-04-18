#include "bits/stdc++.h"
using namespace std;
class MajorityChecker {
public:
    vector<int> faq;
    vector<vector<int>> cnt;
    void init(vector<int> arr) {
        faq = arr;
        std::sort(faq.begin(), faq.end());
        faq.push_back(-1);
        int now = 1;
        for (int i = 0;i < faq.size();i ++) {
            if (faq[i] == faq[i + 1]) {
                now ++;
            } else {
                cnt.push_back({now,faq[i]});
                now = 1;
            }
        }
        std::sort(cnt.begin(), cnt.end(),[&](const vector<int>& a,const vector<int>& b) -> bool  {
            return a[0] < b[0];
        });

    }
    MajorityChecker(vector<int>& arr) {
        init(arr);
    }
    int query(int left, int right, int threshold) {

    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
int main() {
    return 0;
}