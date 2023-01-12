#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string a;
        map<string,string> mapp;
        std::for_each(knowledge.begin(), knowledge.end(), [&](const auto &item) {
            mapp[item[0]] = item[1];
        });
        for (int i = 0;i < s.size();i ++) {
            if (s[i] != '(')
                a.push_back(s[i]);
            else {
                string b;
                i ++;
                while (s[i] != ')') {
                    b.push_back(s[i ++]);
                }
                if (!mapp[b].empty())
                    a.append(mapp[b]);
                else a.push_back('?');
            }
        }
        return a;
    }
};
int main() {
    string s = "(name)is(age)yearsold";
    vector<vector<string>> val = {{"name","bob"},{"age","two"}};
    cout<<(new Solution)->evaluate(s,val);
    return 0;
}