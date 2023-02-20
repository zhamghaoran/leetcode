#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        for (int i = 1;i < suits.size();i ++) {
            if (suits[i] != suits[i - 1]) break;
            if (i == suits.size() - 1) return "Flush";
        }
        std::sort(ranks.begin(), ranks.end());
        for (int i = 2;i < ranks.size();i ++) {
            if (ranks[i] == ranks[i - 1] && ranks[i] == ranks[i - 2]) return "Three of a Kind";
        }
        for (int i = 1;i < ranks.size();i ++) {
            if (ranks[i] == ranks[i - 1]) return "Pair";
        }
        return "High Card";
    }
};
int main() {
    return 0;
}