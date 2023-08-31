#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    int minTrioDegree(int n, vector<vector<int>> &edges) {
        int ans = 0x3f3f3f3f;
        vector<vector<int>> mapp(n + 1,vector<int> (n + 1,0));
        vector<int> de(n + 1,0);
        for (int i = 0;i < edges.size();i ++) {
            mapp[edges[i][0]][edges[i][1]] = 1;
            mapp[edges[i][1]][edges[i][0]] = 1;
            de[edges[i][0]] ++;
            de[edges[i][1]] ++;
        }
        for (int i = 1;i <= n;i ++) {
            for (int j = i + 1;j <= n;j ++) {
                for (int z = j + 1;z <= n;z ++) {
                    if (mapp[i][j] && mapp[i][z] && mapp[j][z]) {
                        ans = min(ans,de[i] + de[j] + de[z] - 6);
                    }
                }
            }
        }
        if (ans == 0x3f3f3f3f) return -1;
        return ans;
    }
};

int main() {

    return 0;
}