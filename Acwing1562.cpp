#include "bits/stdc++.h"
using namespace std;
struct node {
    int f,t,nex;
}rt[100010];
int head[100010];
int cnt;
void add(int x,int y) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
int a,b;
int bfs(int x) {
    vector<int> vis(a + 10,0);
    queue<int> qu;
    qu.push(x);
    int ans = 0;
    vis[x] = 1;
    for (int i = 1;i <= b;i ++) {
        vector<int> tem;
        while (!qu.empty()) {
            tem.push_back(qu.front()),qu.pop();
        }
        for (int j : tem) {
            for (int z = head[j];z;z = rt[z].nex) {
                if (!vis[rt[z].t]) {
                    ans ++;
                    vis[rt[z].t] = 1;
                    qu.push(rt[z].t);
                }
            }
        }
    }
    return ans;
}
int main() {

    cin>>a>>b;
    int x,y;
    for (int i = 1;i <= a;i ++) {
        ::scanf("%d",&x);
        for (int j = 1;j <= x;j ++) {
            ::scanf("%d",&y);
            add(y,i);
        }
    }
    ::scanf("%d",&x);
    for (int i = 1;i <= x;i ++) {
        ::scanf("%d",&y);
        ::printf("%d\n", bfs(y));
    }
    return 0;
}