#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    cin >> a;
    string s;
    cin >> s;
    int ans = 0, f = 0;
    for(int i = 0; i < a; i += 2) {
        if(s[i] == 'G' && s[i + 1] == 'H') {
            ans += f == 2;
            f = 1; //GH组合
        }
        else if(s[i] == 'H' && s[i + 1] == 'G') {
            ans += f == 1;
            f = 2; //HG组合
        }
    }
    if (f == 1)
        ans ++;
    cout<<ans;
    return 0;
}