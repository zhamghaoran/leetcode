#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> fa(n + 1,0);
        for (int i = 1;i <= n;i ++)
            fa[i] = i;
        std::function<int(const int &)> fin = [&](const int & x)  {
            return fa[x] == x ? fa[x] : fa[x] = fin(fa[x]);
        };
        auto unin = [&](int x,int y) {
            x = fin(x);
            y = fin(y);
            fa[x] = y;
        };
        for (auto i : edges) {
            unin(i[0] + 1,i[1] + 1);
        }
        return fin(source + 1) == fin(destination + 1);
    }

};
int main() {
    vector<vector<int>> qaq = {{0,1},{1,2},{2,0}};
    cout<<(new Solution)->validPath(3,qaq,0,2);
}