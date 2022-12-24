#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;
        int i,j;
        i = j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size() && j < word2.size()) {
                if (word2[j] > word1[i])
                    merge.push_back(word2[j ++]);
                else if (word2[j] < word1[i])
                    merge.push_back(word1[i ++]);
                else {
                    int x = 0;
                    while (i + x < word1.size() && j + x < word2.size() && word1[i + x] == word2[j + x]) {
                        x ++;
                    }
                    if (word1[i + x] > word2[j + x])
                        merge.push_back(word1[i ++]);
                    else
                        merge.push_back(word2[j ++]);

                }
            } else if (i < word1.size())
                merge.push_back(word1[i ++]);
            else
                merge.push_back(word2[j ++]);
        }
        return merge;
    }

};

int main() {
    return 0;
}