#include "bits/stdc++.h"

using namespace std;
int val[1010][1010];
int cha[1010][1010];
int val1[1010][1010];

void insert(int x1, int y1, int x2, int y2, int vall) {
    val[x1][y1] += vall;
    val[x1][y2 + 1] -= vall;
    val[x2 + 1][y1] -= vall;
    val[x2 + 1][y2 + 1] += vall;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> val1[i][j];
            insert(i, j, i, j, val1[i][j]);
        }
    }
    int x1,y1,x2,y2,ans;
    for (int i = 1;i <= c;i ++) {
        cin>>x1>>y1>>x2>>y2>>ans;
        insert(x1,y1,x2,y2,ans);
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            val[i][j] = val[i][j] + val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1] ;
            cout << val[i][j] << " ";
        }
        puts("");
    }
    return 0;

}