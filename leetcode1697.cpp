#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fin(int x,vector<int>& fa) {
        return fa[x] == x ? fa[x] : fa[x] = fin(fa[x],fa);
    }
    struct qu {
        int x,y,z,i;
    }mappp[1000010];
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        sort(edgeList.begin(),edgeList.end(),[](auto a,auto b) -> bool {
            return a[2] < b[2];
        });
        for (int i = 0;i < queries.size();i ++) {
            mappp[i].x = queries[i][0];
            mappp[i].y = queries[i][1];
            mappp[i].z = queries[i][2];
            mappp[i].i = i;
        }
        sort(mappp,mappp + queries.size(),[](qu a,qu b) -> bool {
            return a.z < b.z;
        });
        vector<int> fa(n,0);
        for (int i = 0;i < fa.size();i ++)
            fa[i] = i;
        auto unin = [&](int x,int y) -> void {
            x = fin(x,fa);
            y = fin(y,fa);
            fa[x] = y;
        };
        int j = 0;
        for (int i = 0;i < queries.size();i ++) {
            while (j < edgeList.size() && edgeList[j][2] < mappp[i].z) {
                unin(edgeList[j][1],edgeList[j][0]);
                j ++;
            }
            ans[mappp[i].i] = fin(mappp[i].x,fa) == fin(mappp[i].y,fa);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> edglist = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    vector<vector<int>> quers = {{0,4,14},{1,4,13}};
    vector<bool> ans = (new Solution)->distanceLimitedPathsExist(5,edglist,quers);
    for (auto i : ans) {
        cout<<i<<endl;
    }
}