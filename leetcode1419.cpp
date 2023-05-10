#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 预处理每个字母在 "croak" 中的上一个字母
        char PREVIOUS['s']; // 's' 保证 "croak" 中的任意字符都不会越界
        const string croak = "croakc";
        for (int i = 1; i < croak.length(); i++)
            PREVIOUS[croak[i]] = croak[i - 1];

        int cnt['s']{};
        for (char ch: croakOfFrogs) {
            char pre = PREVIOUS[ch]; // pre 为 ch 在 "croak" 中的上一个字母
            if (cnt[pre]) // 如果有青蛙发出了 pre 的声音
                cnt[pre]--; // 复用一只
            else if (ch != 'c') // 否则青蛙必须从 'c' 开始蛙鸣
                return -1; // 不符合要求
            cnt[ch]++; // 发出了 ch 的声音
        }
        if (cnt['c'] || cnt['r'] || cnt['o'] || cnt['a'])
            return -1; // 有发出其它声音的青蛙，不符合要求
        return cnt['k']; // 最后青蛙们都发出了 'k' 的声音
    }
};
int main() {
    return 0;
}