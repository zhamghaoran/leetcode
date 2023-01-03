#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<string> val;
        for (int i = 0; i < s.size(); i++) {
            string x;
            while (s[i] != ' ')
                x.push_back(s[i ++]);
            val.push_back(x);
        }
        vector<int> nums;
        std::for_each(val.begin(), val.end(), [&](basic_string<char> item) {
            if (item[0] >= '0' && item[0] <= '9')
                nums.push_back(atoi(item.c_str()));
        });
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    string s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
    cout << (new Solution)->areNumbersAscending(s);
    return 0;
}