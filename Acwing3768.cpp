#include "bits/stdc++.h"
using namespace std;
int main() {
    int a;
    cin>>a;
    string s;
    cin>>s;
    int ans = 0;
    for (int i = 0;i < a;i ++) {
        if (s[i] == 'x') {
            int r = i;
            while (s[r] == 'x')
                r ++;
            r --;
            if (r - i + 1 >= 3) {
                ans += r - i + 1 - 2;
            }
            i = r;
        }
    }
    cout<<ans;
    return 0;
}