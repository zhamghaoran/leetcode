#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<pair<string, string>> val;
    unordered_map<string, set<string>> faq;
    for (int i = 1; i <= a; i++) {
        string x, y;
        cin >> x >> y;
        val.emplace_back(x, y);
    }
    int b;
    cin >> b;
    for (int i = 1; i <= b; i++) {
        string x, y;
        cin >> x >> y;
        faq[x].insert(y);
    }
    for (int i = 0; i < a; i++) {
        string x = val[i].first; // nv
        string y = val[i].second; // nan
        bool qaq = false;
        for (int j = i + 1; j < a; j++) {
            if (faq.count(x) && faq.count(val[j].first)) {
                if (faq[x].count(val[j].second) && faq[val[j].first].count(y)) {
                    qaq = true;
                    break;
                }
            }
        }
        if (qaq)
            puts("Unsafe");
        else puts("Safe");
    }
    return 0;
}
/**
2
Melanie Ashley
Scarlett Charles
1
Scarlett Ashley

5
a b
c d
a e
q f
g g
5
a d
c b
a c
z z
b g

*/