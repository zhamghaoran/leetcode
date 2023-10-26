#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int x = num;
        while (num) {
            int y = num % 10;
            if (x % y == 0 )
                ans ++;
            num /= 10;
        }
        return ans;
    }
};
int main() {

    return 0;
}