#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence2.size() > sentence1.size())
            swap(sentence1, sentence2);
        vector<string> s1;
        vector<string> s2;
        string faq;
        for (const auto& i : sentence1) {
            if (i != ' ')
                faq.push_back(i);
            else
                s1.push_back(faq),faq = "";
        }
        s1.push_back(faq);
        faq = "";
        for (auto i : sentence2) {
            if (i != ' ')
                faq.push_back(i);
            else
                s2.push_back(faq),faq = "";
        }
        s2.push_back(faq);
        int i = 0;
        int j = s2.size() - 1;
        while (i < s2.size() && s1[i] == s2[i]) {
            i ++;
        }
        for (int x = s1.size() - 1;x >= 0; x --) {
            if (j >= 0 && s1[x] == s2[j])
                j --;
            else
                break;
        }
        return i > j;
    }
};

int main() {
    string a = "Eating right now";
    string b = "Eating";
    cout<<(new Solution)->areSentencesSimilar(a,b);
    return 0;
}