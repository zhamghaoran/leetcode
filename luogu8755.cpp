#include "bits/stdc++.h"

using namespace std;
int val[200010];
int main() {
    //什么时候完成，增加多少算力。
    int n, m;
    cin >> n >> m;
    vector<priority_queue<pair<int,int>>> finishedTask(n + 2,priority_queue<pair<int,int>>());
    for (int i = 1; i <= n; i++) {
        ::scanf("%d", &val[i]);
    }
    int a,b,c,d;
    for (int i = 1;i <= m;i ++) {
        ::scanf("%d%d%d%d",&a,&b,&c,&d);
        while (!finishedTask[b].empty() && abs(finishedTask[b].top().first) <= a) {
            val[b] += finishedTask[b].top().second;
            finishedTask[b].pop();
        }
        if (val[b] >= d) {
            val[b] -= d;
            ::printf("%d\n",val[b]);
            finishedTask[b].emplace(-a - c,d);
        } else {
            ::printf("%d\n",-1);
        }
    }
    return 0;
}