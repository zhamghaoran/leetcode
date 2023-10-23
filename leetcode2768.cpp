#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        int ans = 0;
        for (string i: details) {
            int num = i[11] - '0';
            num = num * 10 + i[12] - '0';
            if (num > 60) ans++;
        }
        return ans;
    }
};

int main() {

    return 0;
}