#include "bits/stdc++.h"

using namespace std;

void printNo(int i) {
    printf("Case #%d: IMPOSSIBLE\n", i);
}

bool pd(string a, string b) {
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j])
            i++, j++;
        else j++;
    }
    if (i == a.size())
        return true;
    return false;
}

void printYes(int x, int i) {
    printf("Case #%d: %d\n", i, x);
}

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        string c, d;
        cin >> c >> d;
        if (c.size() > d.size()) {
            printNo(i);
            continue;
        }
        if (!pd(c, d)) {
            printNo(i);
        } else {
            printYes(d.size() - c.size(), i);
        }
    }
    return 0;
}