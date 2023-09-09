#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> val;
    int be = a;
    int low = 1;
    for (int i = 1; i <= a - 1; i += 2) {
        val.push_back(be);
        val.push_back(low);
        be--;
        low++;
    }
    if (a & 1) val.push_back(be);
    for (int i = 0; i < a; i++)
        cout << val[i] << " ";
    return 0;
}
