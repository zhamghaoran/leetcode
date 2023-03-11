#include "bits/stdc++.h"
using namespace std;
int main() {
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    int j = 0;
    for (char & i : c) {
        if (i >= 'A' && i <= 'Z')
            i = char(i - 'A' + 'a');
    }
    for (char & i : d) {
        if (i >= 'A' && i <= 'Z')
            i = char (i - 'A' + 'a');
    }
    for (char i : c) {
        if (d[j] == i)
            j ++;
    }
    if (j == d.size())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}