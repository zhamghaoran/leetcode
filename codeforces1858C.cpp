#include "bits/stdc++.h"

using namespace std;

vector<int> zhi;
int vis[100010];

void shai() {
    for (int i = 2; i * i < 100010; i++) {
        if (!vis[i]) {
            zhi.push_back(i);
            for (int j = i; j * i < 100010; j++) {
                vis[i * j] = 1;
            }
        }
    }
}

void solve(int x) {

    vector<int> ans;
    for (int i = 1; i <= x; i += 2) {
        for (int j = i; j <= x; j *= 2) {
            ans.push_back(j);
        }
    }
    std::for_each(ans.begin(), ans.end(), [](int xx) -> void {
        printf("%d ", xx);
    });
    puts("");
}

int main() {
    shai();
    int a;
    cin >> a;
    int x;
    for (int i = 1; i <= a; i++) {
        scanf("%d", &x);
        solve(x);
    }
    return 0;
}