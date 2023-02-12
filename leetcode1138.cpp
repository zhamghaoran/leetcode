#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string ans;
    void calcY(int disy) {
        if (disy > 0) {
            while (disy > 0) {
                ans.push_back('D');
                disy--;
            }

        }
        if (disy < 0) {
            while (disy < 0) {
                ans.push_back('U');
                disy++;
            }
        }
    }
    void calcX(int disx) {
        if (disx > 0) {
            while (disx) {
                ans.push_back('R');
                disx--;
            }
        }
        if (disx < 0) {
            while (disx < 0) {
                ans.push_back('L');
                disx++;
            }
        }
    }
    void getAns(char a, char b) {
        int aa = a - 'a';
        int bb = b - 'a';
        int ay = aa / 5;
        int ax = aa % 5;
        int by = bb / 5;
        int bx = bb % 5;
        int disx = bx - ax;
        int disy = by - ay;
        if (a == 'z' || b == 'z') {
            if (a == 'z'){
                calcY(disy);
                calcX(disx);
            }
            else {
                calcX(disx);
                calcY(disy);
            }
        } else {
            calcY(disy);
            calcX(disx);
        }

    }
    string alphabetBoardPath(string target) {
        vector<string> faq = {{"abcde"},
                              {"fghij"},
                              {"klmno"},
                              {"pqrst"},
                              {"uvwxy"},
                              {"z"}};
        int nowx = 0;
        int nowy = 0;
        getAns('a',target[0]);
        ans.push_back('!');
        for (int i = 1; i < target.size(); i++) {
            getAns(target[i - 1], target[i]);
            ans.push_back('!');
        }
        return ans;
    }
};

int main() {
    cout<<(new Solution)->alphabetBoardPath("leet");
    return 0;
}