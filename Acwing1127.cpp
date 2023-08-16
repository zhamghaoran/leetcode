#include "bits/stdc++.h"

using namespace std;
struct node {
    int f, t, val, nex;
} rt[100010];
int head[100010];
int cnt;

void add(int x, int y, int z) {
    rt[++cnt].f = x;
    rt[cnt].t = y;
    rt[cnt].val = z;
    rt[cnt].nex = head[x];
    head[x] = cnt;
}

int farm[100010];

void dij() {

}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y, z;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &x);
        farm[x]++;
    }
    for (int i = 1; i <= c; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= c; i++) {

    }
    return 0;
}