#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int now = 1;
        bool ma;
        for (int i = 1; i <= time; i++) {
            if (ma) {
                now++;
            } else now--;
            if (now == n) {
                ma = false;
            }
            if (now == 1)
                ma = true;
        }
        return now;
    }
};

int main() {
    return 0;
}