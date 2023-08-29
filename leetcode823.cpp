#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> faq;
    long long ans = 0;
    long long mod = 1e9 + 7;
    vector<long long> val;
    vector<bool> vis;

    void dfs(int x) {

        for (auto i: faq[x]) {
            if (!vis[i.first]) {
                dfs(i.first);
            }
            if (!vis[i.second]) {
                dfs(i.second);
            }
            if (!vis[x]) {
                val[x] += val[i.first] * val[i.second];
                val[x] %= mod;
            }
        }
        vis[x] = true;
    }

    int numFactoredBinaryTrees(vector<int> &arr) {
        faq = vector<vector<pair<int, int>>>(arr.size() + 1);
        val = vector<long long>(arr.size() + 1, 1);
        vis = vector<bool>(arr.size() + 1);
        map<int, pair<int, int>> mapp;
        for (int i = 0; i < arr.size(); i++) {
            mapp[arr[i]] = make_pair(i, 1);
        }

        for (int i = 0;i < arr.size();i ++) {
            for (int j = 0;j < arr.size();j ++) {
                if (i == j)
                    continue;
                if (arr[i] % arr[j] == 0 && mapp.count(arr[i] / arr[j])) {
                    faq[mapp[arr[i]].first].emplace_back(j,mapp[arr[i] / arr[j]].first);
                }
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (!vis[i]) {
                dfs(i);
            }
            ans += val[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};

int main() {
    vector<int> faq  = {2,4,5,10};
    cout<<(new Solution)->numFactoredBinaryTrees(faq);
    return 0;
}