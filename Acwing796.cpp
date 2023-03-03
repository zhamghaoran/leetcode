#include "bits/stdc++.h"
using namespace std;
int mapp[1010][1010];
int val[1010][1010];
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    for (int i = 1;i <= a;i ++) {
        for (int j = 1;j <= b;j ++) {
            ::scanf("%d",&mapp[i][j]);
        }
    }
    for (int i = 1;i <= a;i ++) {
        for (int j = 1;j <= b;j ++) {
            val[i][j] = val[i - 1][j] + val[i][j - 1] + mapp[i][j] - val[i - 1][j - 1];
        }
    }
    int x1,y1,x2,y2;
    for (int i = 1;i <= c;i ++) {
        ::scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ::printf("%d\n",val[x2][y2] - val[x2][y1 - 1] - val[x1 - 1][y2] + val[x1 - 1][y1 - 1]);
    }
    return 0;
}