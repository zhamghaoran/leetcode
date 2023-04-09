#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int> mapp;
        for (int i = 0;i < s.size();i ++) {
            if (!mapp.count(s[i]))
                mapp[s[i]] = i;
            else {
                if (distance[s[i] - 'a'] != i - mapp[s[i]] - 1)
                    return false;
            }
        }
        return true;
    }
};
int main() {

    return 0;
}