#include "bits/stdc++.h"
using namespace std;
int mapp[1010][1010];
int val[101][101];
int xxx[4] = {0,0,1,-1};
int yyy[4] = {1,-1,0,0};
int main() {
    int a,b;
    cin>>a>>b;
    for (int i = 1;i <= a;i  ++) {
        for (int j = 1;j <= b;j ++) {
            cin>>mapp[i][j];
        }
    }
    ::memset(val,0x3f,sizeof val);
    val[1][1] = 0;
    priority_queue<pair<int,pair<int ,int>>> ans;
    ans.emplace(0, make_pair(1,1));
    while (!ans.empty()) {
        int xx = ans.top().second.first;
        int yy = ans.top().second.second;
        ans.pop();
        for (int i = 0;i < 4;i ++) {
            if (xx + xxx[i] <= a && xx + xxx[i] > 0 && yy + yyy[i] <= b && yy + yyy[i] > 0 && mapp[xx + xxx[i]][yy + yyy[i]] == 0) {
                if (val[xx + xxx[i]][yy + yyy[i]] > val[xx][yy] + 1) {
                    val[xx + xxx[i]][yy + yyy[i]] = val[xx][yy] + 1;
                    ans.emplace( -val[xx + xxx[i]][yy + yyy[i]], make_pair(xx + xxx[i],yy + yyy[i]));
                }
            }
        }
    }
    cout<<val[a][b];
    return 0;
}