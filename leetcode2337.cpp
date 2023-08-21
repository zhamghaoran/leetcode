#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        int n = start.size();
        while (i < n && j < n) {
            if (start[i] == '_') {
                i++;
                continue;
            }
            if (target[j] == '_') {
                j++;
                continue;
            }
            if (start[i] != target[j]) {
                return false;
            } else if (start[i] == 'L') {
                if (i >= j) {
                    i++;
                    j++;
                } else {
                    return false;
                }
            } else if (target[j] == 'R') {
                if (j >= i) {
                    i++;
                    j++;
                } else
                    return false;
            }
        }
        if (i == n) {
            while (j < i) {
                if (target[j] != '_') {
                    return false;
                }
                j++;
            }
        } else {
            while (i < j) {
                if (start[i] != '_') {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};

int main() {
    cout << (new Solution)->canChange("_L__R__R_", "L______RR");
    return 0;
}