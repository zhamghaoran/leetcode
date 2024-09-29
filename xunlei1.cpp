#include "bits/stdc++.h"

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    map<char, char> mapp;
    bool res = true;
    for (int i = 0; i < a.size(); i++) {
        if (!mapp.count(a[i])) {
            mapp[a[i]] = b[i];
        } else {
            if (mapp[a[i]] != b[i]) {
                res = false;
                break;
            }
        }
    }
    if (res) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}