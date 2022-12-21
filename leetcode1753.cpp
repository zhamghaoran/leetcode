#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        while ((a == 0) + (b == 0) + (c == 0) < 2) {
            if (a < b)
                swap(a,b);
            if (a < c)
                swap(a,c);
            if (b < c)
                swap(b,c);
            ans ++;
            a --;
            b --;
        }
        return ans;
    }
};

int main() {
    return 0;
}