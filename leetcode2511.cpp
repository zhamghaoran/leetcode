#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int ans = 0;
        int nex = -1;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] == -1)
                nex = i;
            if (forts[i] == 1) {
                if (nex != -1)
                    ans = max(ans, i - nex - 1);
                int tem = 0;
                for (int j = i + 1; j < forts.size(); j++) {
                    if (forts[j] == -1) {
                        ans = max(ans, tem);
                        break;
                    }
                    if (forts[j] == 0) tem ++;
                    if (forts[j] == 1) break;

                }
                nex = -1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> qaq{-1,-1,0,1,0,0,1,-1,1,0};
    cout << (new Solution)->captureForts(qaq);
    return 0;
}