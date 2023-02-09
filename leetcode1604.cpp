#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        string name = keyName[0];
        string beginTime = keyTime[0];
        for (int i = 1;i < keyName.size();i ++) {
            if (keyName[i] == name) {
                const char *h = beginTime.substr(0, 1).c_str();
                int h1 = atoi(h);
            }
        }
    }
};
int main() {
    return 0;
}