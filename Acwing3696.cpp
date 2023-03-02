#include "bits/stdc++.h"

using namespace std;
struct node {
    int f, t, nex;
} rt[200300];
int head[200300];
int cnt;
int du[200300];
int a, b;
int neww[200300];
int cnt1;
void add(int x, int y) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}
bool topSort() {
    int faq = 0;
    queue<int> qu;
    for (int i = 1;i <= a;i ++)
        if (!du[i])
            qu.push(i),faq ++;
    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        neww[x] = ++ cnt1;
        for (int i = head[x];i;i = rt[i].nex) {
            du[rt[i].t] --;
            if (!du[rt[i].t])
                qu.push(rt[i].t),faq ++;;
        }
    }
    return faq == a;

}
void init() {
    ::memset(du,0,sizeof du);
    ::memset(head,0,sizeof head);
    cnt = 0;
    cnt1 = 0;
}
void solve() {
    init();
    ::scanf("%d%d",&a,&b);
    int x,y,z;
    vector<pair<int,int>> faq;
    for (int i = 1; i <= b; i++) {
        scanf("%d%d%d",&x,&y,&z);
        if (x) add(y,z),du[z] ++;
        else faq.emplace_back(y,z);
    }
    if (!topSort()) puts("NO");
    else {
        puts("YES");
        for (int i = 1;i <= cnt;i ++) {
            printf("%d %d\n",rt[i].f,rt[i].t);
        }
        std::for_each(faq.begin(), faq.end(), [&](pair<int,int> &item) {
            if (neww[item.second] < neww[item.first])
                printf("%d %d \n",item.second,item.first);
            else
                printf("%d %d \n",item.first,item.second);
        });
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}