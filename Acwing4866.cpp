#include "bits/stdc++.h"

using namespace std;
int fa[1000010];
int siz[100010];
int aa[100010];
int bb[100010];
int fin(int x) {
    if (fa[x] != x)
        return fa[x] = fin(fa[x]);
    return fa[x];
}
void unin(int x,int y) {
    x = fin(x);
    y = fin(y);
    fa[y] = x;
    siz[x] += siz[y];
}
int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    for (int i = 1;i <= b;i ++) {
        scanf("%d%d",&aa[i],&bb[i]);
    }
    for (int i = 1; i <= b; i++) {
        for (int j = 1;j <= a;j ++)
            fa[j] = j,siz[j] = 1;
        int more = 0;
        for (int j = 1;j <= i;j ++) {
            if (fin(aa[j]) != fin(bb[j])) {
                unin(aa[j],bb[j]);
            } else more ++;
        }
        vector<int> maxx;
        for (int j = 1;j <= a;j ++) {
            if (fin(j) == j) {
                maxx.push_back(siz[j] - 1);
            }
        }
        int ans = 0;
        std::sort(maxx.begin(), maxx.end(),[&](auto a,auto b) -> bool {
            return a > b;
        });
        ans = maxx[0];
        if (more) {
            int xx = 1;
            while (more) {
                if (!maxx[xx]) {
                    break;
                }
                ans += maxx[xx ++] + 1;
                more --;
            }
            ans += more;
        } else ans = maxx[0];
        ::printf("%d\n",ans);
    }
    return 0;
}