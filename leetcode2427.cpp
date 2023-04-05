#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int commonFactors(int a, int b) {
        int x = __gcd(a,b);
        int ans = 0;
        int qaq = x;
        for (int i = 1;i * i<= x;i ++) {
            if (x % i == 0) {
                ans ++;
                if (i * i != x)
                    ans ++;
            }

        }
        return ans;
    }
};
int main() {

    return 0;
}