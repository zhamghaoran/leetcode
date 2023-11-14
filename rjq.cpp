#include "bits/stdc++.h"

using namespace std;

string removeDigits(string num, int n) {
    int len = num.length();
    if (n == len) {
        return "";
    }
    for (int i = 0; i < n; ++i) {
        int j = 0;
        while (j < num.length() - 1 && num[j] <= num[j + 1]) {
            ++j;
        }
        num.erase(j, 1);
    }
    int i = 0;
    while (i < num.length() - 1 && num[i] == '0') {
        ++i;
    }
    num.erase(0, i);
    return num;
}

int main() {
    cout << removeDigits("32415", 2);
}