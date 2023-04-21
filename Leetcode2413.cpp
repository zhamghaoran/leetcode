#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n & 1) ? n * 2 : n;
    }
};
int main() {

    return 0;
}