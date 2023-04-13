#include "bits/stdc++.h"
using namespace std;
int val[100010];
int cnt[100010];
int faq[100010][11];
int maxx[20];
int main() {
    int a;
    cin>>a;
    int qaq;
    int x;
    for (int i = 1;i <= a;i ++) {
        scanf("%d",&x);
        val[i] = x;
        qaq = 0;
        while (x) {
            faq[i][++ qaq] = x % 10;
            x /= 10;
        }
        cnt[i] = qaq;
    }
    int ans = 0;
    for (int i = 1;i <= a;i ++) {
        int be = faq[i][cnt[i]];
        int end = faq[i][1];
        maxx[end] = max(maxx[end],maxx[be] + 1);
        ans = max(ans,maxx[end]);
    }
    cout<<a - ans;
    return 0;
}