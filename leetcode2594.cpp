#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    bool pd(long long x, vector<int> &ranks, int cars) {
        long long total = 0;
        for (auto i: ranks) {
            total += (long long)(sqrt(x / i));
        }
        return total >= cars;
    }

    long long repairCars(vector<int> &ranks, int cars) {
        long long l = 1;
        long long r = 0x7f7f7f7f;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (pd(mid, ranks, cars)) {
                r = mid;
            } else l = mid + 1;
        }
        return l;
    }
};

int main() {
    return 0;
}