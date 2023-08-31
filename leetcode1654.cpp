#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ans;
    vector<int> val;
    int aa, bb;
    set<int> s;

    void dfs(int pos, bool ma) {
        if (ma && pos - bb >= 0 && !s.count(pos - bb)) {
            if (val[pos - bb] >= val[pos] + 1) {
                val[pos - bb] = val[pos] + 1;
                dfs(pos - bb, false);
            }
        } else if (pos + aa < val.size() && !s.count(pos + aa)) {
            if (val[pos + aa] >= val[pos] + 1) {
                val[pos + aa] = val[pos] + 1;
                dfs(pos + aa, true);
            }

        }
    }

    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        aa = a;
        bb = b;
        val = vector<int>(2010, 0x3f3f3f3f);
        val[0] = 0;
        s = set<int>(forbidden.begin(), forbidden.end());
        dfs(0, true);
        if (val[x] == 0x3f3f3f3f)
            return -1;
        return val[x];
    }
};

int main() {

    return 0;
}