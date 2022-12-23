#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations) {
        int ans = 0;
        for (auto i: operations) {
            if (i[1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};

int main() {
    return 0;
}