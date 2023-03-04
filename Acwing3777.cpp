#include "bits/stdc++.h"

using namespace std;
int a;
string b;

void trans(char &x) {
    if (x == 'W') x = 'B';
    else x = 'W';
}

bool check(char c) {
    vector<int> ans;
    string val = b;
    for (int i = 0; i < a - 1; i++) {
        if (val[i] != c) {
            ans.push_back(i + 1);
            trans(val[i]);
            trans(val[i + 1]);
        }
    }
    if (val.back() != c) return false;
    cout << ans.size() << endl;
    for (auto i: ans)
        cout << i << " ";
    if (!ans.empty())
        puts("");
    return true;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (!check('B') && !check('W')) puts("-1");
    }
    return 0;
}