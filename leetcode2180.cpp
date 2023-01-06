#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1;i <= num;i ++) {
            int x = i;
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (!((sum) & 1))
                ans ++;
        }
        return ans;
    }
};
int main() {

    return 0;
}