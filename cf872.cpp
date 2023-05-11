#include <bits/stdc++.h>
using namespace std;
bool pd(string s) {
    for (int i = 1;i < s.size();i ++) {
        if (s[i] != s[i - 1])
            return false;
    }
    return true;
}
int main() {
    int a;
    cin>>a;
    while(a --) {
        string s;
        cin>>s;
        if (s.size() == 1) {
            cout<<-1<<endl;
            continue;
        }
        if (s[0] == s[1]) {
            if (pd(s))
                cout<<-1<<endl;
            else
                cout<<s.size() - 1<<endl;
        } else {
            cout<<s.size() - 1<<endl;
        }
    }
    return 0;
}