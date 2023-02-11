#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int fillCups(vector<int>& amount) {
        std::sort(amount.begin(), amount.end());
        if  (amount[2] > amount[0] + amount[1]) {
            return amount[2];
        } else {
            return (amount[2] + amount[0] + amount[1] + 1) / 2;
        }
    }
};
int main() {
    return 0;
}