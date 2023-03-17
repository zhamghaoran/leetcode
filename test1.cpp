#include "bits/stdc++.h"

using namespace std;
struct ndoe {
    int f, t, val, nex;
} rt[1000010];
int head[100010];
int cnt;
map<int,vector<int>> viss;
void add(int x, int y, int z) {
    rt[++ cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int a, b;

int trans(int x, int y) {
    return (x - 1) * b + y;
}

int mapp[1010][1010];
int ans[100010];
int vis[1000010];

int main() {
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            ::scanf("%d", &mapp[i][j]);
            viss[mapp[i][j]].push_back(trans(i,j));
        }
    }
    ::memset(ans, 0x3f, sizeof ans);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i - 1 > 0) {
                add(trans(i, j), trans(i - 1, j), abs(mapp[i][j] - mapp[i - 1][j]));
                add(trans(i - 1, j), trans(i, j), abs(mapp[i][j] - mapp[i - 1][j]));
            }
            if (j - 1 > 0) {
                add(trans(i, j), trans(i, j - 1), abs(mapp[i][j] - mapp[i][j - 1]));
                add(trans(i, j - 1), trans(i, j), abs(mapp[i][j] - mapp[i][j - 1]));
            }
        }
    }
//    for (int i = 1; i <= a; i++) {
//        for (int j = 1; j <= b; j++) {
//            for (int i1 = 1; i1 <= a; i1++) {
//                for (int j1 = 1; j1 <= b; j1++) {
//                    if  (i == i1 && j == j1)
//                        continue;
//                    if (mapp[i][j] == mapp[i1][j1]) {
//                        add(trans(i, j), trans(i1, j1), 0);
//                        add(trans(i1,j1), trans(i,j),0);
//                    }
//
//                }
//            }
//        }
//    }
    std::for_each(viss.begin(), viss.end(), [&](pair<const int, vector<int>>& item) {
        vector<int> qaq = item.second;
        for (int i = 0;i < qaq.size();i ++) {
            for(int j = i + 1;j < qaq.size();j ++)
                add(qaq[i],qaq[j],0), add(qaq[j],qaq[i],0);
        }
    });
    priority_queue<pair<int, int> > faq;
    ans[1] = 0;
    faq.emplace(0, 1);
    while (!faq.empty()) {
        int qaq = faq.top().second;
        faq.pop();
        if (vis[qaq])
            continue;
        vis[qaq] = 1;
        for (int i = head[qaq]; i; i = rt[i].nex) {
            if (ans[rt[i].t] > ans[qaq] + rt[i].val) {
                ans[rt[i].t] = ans[qaq] + rt[i].val;
                faq.emplace(-ans[rt[i].t], rt[i].t);
            }
        }
    }
    cout << ans[trans(a, b)];
    return 0;

}
/**
3 3
1 4 6
8 8 2
6 3 9

*/