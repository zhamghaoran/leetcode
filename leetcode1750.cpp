#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char mark = s[i];
            int cnt = 0;
            int cnt1 = 0;
            while (s[i + cnt] == mark && i + cnt < s.size()) cnt ++;
            while (s[j - cnt1] == mark && j - cnt1 > 0) cnt1 ++;
            if (cnt1 == 0)
                return max(j - i + 1,0);
            i += cnt;
            j -= cnt1;
        }
        return max(j - i + 1,0);
    }
};

int main() {
    cout<<(new Solution)->minimumLength("bbbbbbbbbbbbbbbbbbb");
    return 0;
}