#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ans;
    int a;
    vector<string> arrr;

    void dfs(int num, int len, vector<int> vis) {
        if (num >= a) {
            ans = max(ans, len);
            return;
        }
        dfs(num + 1, len, vis);
        bool faq = true;
        string c = arrr[num];
        std::sort(c.begin(), c.end());
        for (int i = 1;i < c.size();i ++) {
            if(c[i] == c[i - 1])
                return;
        }
        for (char i: c) {
            if (vis[i - 'a']) {
                faq = false;
                break;
            }
        }
        if (!faq)
            return;
        for (char i: c) {
            vis[i - 'a'] = 1;
        }
        dfs(num + 1, len + arrr[num].size(), vis);
        for (char i: arrr[num]) {
            vis[i - 'a'] = 0;
        }

    }

    int maxLength(vector<string> &arr) {
        ans = 0;
        arrr = arr;
        a = arr.size();
        vector<int> vis(30, 0);
        dfs(0, 0, vis);
        return ans;
    }
};

int main() {
    vector<string> faq = {"abcdefghijklm","bcdefghijklmn","cdefghijklmno","defghijklmnop","efghijklmnopq","fghijklmnopqr","ghijklmnopqrs","hijklmnopqrst","ijklmnopqrstu","jklmnopqrstuv","klmnopqrstuvw","lmnopqrstuvwx","mnopqrstuvwxy","nopqrstuvwxyz","opqrstuvwxyza","pqrstuvwxyzab"};
    cout << (new Solution)->maxLength(faq);
    return 0;
}