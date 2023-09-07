#include <bits/stdc++.h>

using namespace std;
set<string> faq;
map<string, vector<string>> name;
map<string, int> nums;
map<string, string> zhudian;

bool pdxioaxie(string s) {
    for (char i : s) {
        if (i > 'z' || i < 'a')
            return false;
    }
    return true;
}

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        string x, y;
        cin >> x >> y;
        if (!pdxioaxie(x) || !pdxioaxie(y)) {
            continue;
        }
        if (!faq.count(x)) {
            faq.insert(x);
            vector<string> na{y};
            name[x] = na;
            zhudian[x] = y;
        } else {
            vector<string> na = name[x];
            if (std::find(na.begin(), na.end(), y) == na.end()) {
                na.push_back(y);
                name[x] = na;
                nums[x]++;
            }
        }
    }
    vector<pair<string, vector<string>>> faq(name.begin(), name.end());
    std::sort(faq.begin(), faq.end(), [&](const auto a, const auto b) -> bool {
        return a.first < b.first;
    });
    for (const auto& i: faq) {
        cout << i.first << " " << zhudian[i.first] << " " << nums[i.first]<<endl;
    }
    return 0;
}
