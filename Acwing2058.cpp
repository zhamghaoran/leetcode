#include "bits/stdc++.h"
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    set<int> list;
    for (int i = a.size() - 1;i >= 0;i --) {
        int ans = 0;
        for (int j = a.size();j >= 0;j --) {
            if (j == i) {
                ans <<= !(a[j] - '0');
            } else ans <<= (a[j] - '0');
        }
        list.insert(ans);
    }
    for (int i = b.size() - 1;i >= 0;i --) {
        for (int j = b.size() - 1;j >= 0;j --) {
            int ans = 0;
            int cheng = 1;
            int x = b[j] - '0';
            if (i == j) {
                if (x + 1 <= 2) {
                    ans += cheng * (x + 1);
                }
                if (x + )
            } else {

            }
        }
    }
    return 0;
}