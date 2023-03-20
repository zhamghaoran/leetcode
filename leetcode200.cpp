#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fa[1000010];
    int a,b;
    int fin(int x) {
        if (fa[x] == x)
            return fa[x];
        return fa[x] = fin(fa[x]);
    }
    int trans(int x,int y) {
        return x * (b + 1) + y;
    }
    void unin(int x,int y) {
        x = fin(x);
        y = fin(y);
        fa[x] = y;
    }
    int numIslands(vector<vector<char>>& grid) {
        a = grid.size() - 1;
        b = grid[0].size() - 1;
        for (int i = 0;i <= (a + 1) * (b + 1);i ++)
            fa[i] = i;
        for (int i = 0;i <= a;i ++) {
            for (int j = 0;j <= b;j ++) {
                if (grid[i][j] == '1') {
                    int x = trans(i,j);
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        unin(x,trans(i - 1,j));
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        unin(x,trans(i,j - 1));
                }
            }
        }
        int ans = 0;
        for (int i = 0;i <= a;i ++) {
            for (int j = 0;j <= b;j ++) {
                if (grid[i][j] == '1') {
                    int x =trans(i,j);
                    if (x == fin(x))
                        ans ++;
                }
            }
        }
        return ans;
    }
};

int main() {
    int m,n;

    cin>>n>>m;
    vector<vector<char>> mapp(n,vector<char>(m));
    for (int i = 0;i < n;i ++)
        for (int j = 0;j < m;j ++)
            cin>>mapp[i][j];
    cout<<(new Solution)->numIslands(mapp);
}