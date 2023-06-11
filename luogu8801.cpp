#include "bits/stdc++.h"

using namespace std;
string ans;
string maxString(string a,string b) {
    for (int i = 0;i < a.size();i ++) {
        if (a[i]  < b[i])
            return b;
        else if(a[i] > b[i])
            return a;
    }
    return a;
}
void dfs(int i, int x, int y, string tem) {
    if (i >= tem.size()) {
        ans = maxString(tem,ans);
        return;
    }
    int ac1 = '9' - tem[i];
    int ac2 = 9 - ac1 + 1;
    char yuan = tem[i];
    if (ac2 <= y) {
        tem[i] = '9';
        dfs(i + 1, x, y - ac2, tem);
        tem[i] = yuan;
    } else {
        dfs(i + 1, x, y, tem);
    }
    if (ac1 <= x) {
        tem[i] = '9';
        dfs(i + 1, x - ac1, y, tem);
        tem[i] = yuan;
    } else {
        tem[i] += x;
        dfs(i + 1, 0, y, tem);
        tem[i] = yuan;
    }
}

int main() {
    string a;
    int c, d;
    cin >> a >> c >> d;
    for(int i = 0;i < a.size();i ++) {
        ans[i] = '0';
    }
    dfs(0, c, d, a);
    cout << ans;
    return 0;
}