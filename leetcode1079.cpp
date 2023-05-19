#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int ans = 0;
    int numTilePossibilities(string tiles) {
        map<char,int> coun;
        std::for_each(tiles.begin(), tiles.end(), [&](const char &item) {
            coun[item] ++;
        });
        dfs(coun);
        return ans - 1;
    }
    void dfs(map<char,int>& faq) {
        ans ++;
        if (faq.empty())
            ans ++;
        for (pair<char,int> item : faq) {
            if (faq[item.first] > 0) {
                faq[item.first] -= 1;
                dfs(faq);
                faq[item.first] += 1;

            }
        }
    }
};
int main() {
    cout<<(new Solution)->numTilePossibilities("V");
    return 0;
}