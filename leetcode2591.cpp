#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        int ans = 0;
        money -= children;
        if (money < 0)
            return -1;
        ans = min(money / 7, children);
        int mod = money % 7;
        if (ans == children && money - children * 7 > 0) {
            ans--;
        } else if (mod == 3 && ans == children - 1) {
            ans--;
        }
        return ans;
    }
};

int main() {
    return 0;
}