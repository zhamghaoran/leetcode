#include "bits/stdc++.h"

using namespace std;

void solve() {
    string qaq;
    int n,k;
    scanf("%d%d",&n,&k);
    cin >> qaq;
    int a = qaq.size();
    vector<int> one(a);
    vector<int> zero(a);
    for (int i = 0;i < a;i ++) {
        one[i + 1] += one[i];
        zero[i + 1] += zero[i];
        if (qaq[i] == '1') {
            one[i + 1] ++;
        } else zero[i + 1] ++;

}

int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        solve();
    }
    return 0;
}