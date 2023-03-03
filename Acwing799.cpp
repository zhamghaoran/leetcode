#include <bits/stdc++.h>
using namespace std;
int a;
int val[1000010];
int tong[100010];
int main() {
    cin>>a;
    for(int i = 1;i <= a;i ++)
        cin>>val[i];
    int maxx = 0;
    int last = 1;
    for(int i = 1;i <= a;i ++) {
        for(int j = last;j <= a;j ++) {
            if(!tong[val[j]])
                tong[val[j]] ++;
            else {
                maxx = max(maxx,j - i);
                last = j;
                break;
            }
            if(j == a)
                maxx = max(maxx,j - i + 1);
        }
        tong[val[i]] --;
    }
    cout<<maxx;
    return 0;
}
