#include "bits/stdc++.h"

using namespace std;
map<int, int> faq;
map<int, int> faqq;
char three[3] = {'0', '1', '2'};

int minn(int x, unsigned int y) {
    return x < y ? x : y;
}

void twototen(string x) {
    int ans = 0;
    for (char i: x) {
        ans *= 2;
        ans += i - '0';

    }
    faq[ans]++;
}

void threetoten(string x) {
    int ans = 0;
    for (char i: x) {
        ans *= 3;
        ans += i - '0';
    }
    faqq[ans]++;
}

int main() {
    string a, b;
    cin >> a >> b;
    int mo = a.size() - 1;
    while (a[mo] == '0') mo--;
    for (int i = 0; i <= minn(mo + 1, a.size() - 1); i ++) {
        string x = a;
        if (x[i] == '1' && i == 0)
            continue;
        if (x[i] == '1')
            x[i] = '0';
        else
            x[i] = '1';
        twototen(x);
    }
    mo = b.size() - 1;
    while (b[mo] == '0')
        mo--;
    for (int i = 0; i <= minn(mo + 1, b.size() - 1); i ++) {
        for (char j: three) {
            if (i == 0 && j == '0')
                continue;
            string x = b;
            if (x[i] != j) {
                x[i] = j;
                threetoten(x);
            }
        }
    }
    std::for_each(faq.begin(), faq.end(), [&](pair<const int, int> item) {
        if (item.second == 1 && faqq[item.first] == 1) {
            cout << item.first;
            exit(0);
        }
    });
    cout<<0;
    return 0;
}