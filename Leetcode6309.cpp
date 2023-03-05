#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int zhi[1000030];
    int val[1000010];
    int cnt;
    map<int, int> qian;
    map<int, int> hou;
    void shai() {
        cnt = 0;
        ::memset(zhi,0,sizeof zhi);
        for (int i = 2; i <= 1000010; i++) {
            if (!zhi[i]) {
                val[++cnt] = i;
                for (int j = i; (long long) i * (long long) j <= 1000010; j++) {
                    zhi[i * j] = 1;
                }
            }
        }
    }

    void add(int x) {
        for (int i = 1; i <= cnt; i++) {
            if (x == val[i]) {
                qian[x] ++;
                break;
            }
            if (x % val[i] == 0) {
                while (x % val[i] == 0) {
                    x /= val[i];
                    qian[val[i]] ++;
                }
            }
        }
    }
    void del(int x) {
        for (int i = 1; i <= cnt; i++) {
            if (x == val[i]) {
                qian[x] --;
                hou[x] ++;
                break;
            }
            if (x % val[i] == 0) {
                while (x % val[i] == 0) {
                    x /= val[i];
                    qian[val[i]] --;
                    hou[val[i]] ++;
                }
            }
        }
    }
    bool pd() {
        bool ans = true;
        std::for_each(qian.begin(), qian.end(), [&](const pair<int,int> &item) {
           if (hou[item.first] > 0 && item.second > 0) {
               ans = false;
               return ;
           }
        });
        return ans;
    }
    int findValidSplit(vector<int> &nums) {
        shai();
        for (int num : nums) {
            add(num);
        }
        for (int i = 0;i < nums.size() - 1;i ++ ) {
            del(nums[i]);
            if (pd()) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> faq = {4,7,15,8,3,5};
    cout<<(new Solution)->findValidSplit(faq);
    return 0;
}