#include "bits/stdc++.h"

int pd(int n,std::vector<int> val) {
    int ans = 0;
    int res = 0x3f3f3f3f;
    for (int i = 1;i <= n;i ++) {
        if (val[i] == 1) {
            int cnt = 0;
            int j = i + 1;
            while (j <= n) {
                if (val[j] == 1) {
                    cnt ++;
                    ans += j - i - cnt;
                }
                j ++;
            }
            cnt = 0;
            j = i - 1;
            while (j >= 1) {
                if (val[j] == 1) {
                    cnt ++;
                    ans += i - j - cnt;
                }
                j --;
            }
            res = std::min(res,ans);
        }
    }
    return res;
}
int solution(int n, std::string s) {
    std::vector<int> val(n + 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = i;j <= n;j ++)
            val[j - i + 1] = (s[j - 1] == 'F' ? 1 : 0);
        for (int x = 1;x < i;x ++)
            val[x + (n - i + 1)] = (s[x - 1] == 'F' ? 1 : 0);

        ans = std::min(ans, pd(n,val));
    }
    return ans;
}

int main() {
    int a;
    std::string b;
    std::cin >> a >> b;
    std::cout << solution(a, b);
    return 0;
}