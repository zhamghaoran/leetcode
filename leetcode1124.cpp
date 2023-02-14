#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int a = hours.size();
        vector<int> qian(a + 1);
        unordered_map<int,int> mapp;
        for (int i = 0;i < a;i ++) {
            if (hours[i] > 8)
                qian[i + 1] = qian[i] + 1;
            else
                qian[i + 1] = qian[i] - 1;
            if (!mapp.count(qian[i + 1]))
                mapp[qian[i + 1]] = i + 1;
        }
        int ans = 0;
        for (int i = 1;i <= a;i ++) {
            if (qian[i] > 0)
                ans = max(ans,i);
            else {
                if (mapp.count(qian[i] - 1))
                    ans = max(ans,i - mapp[qian[i] - 1]);
            }

        }
        return ans;
    }
};
int main() {
    return 0;
}