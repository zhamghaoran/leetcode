#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        vector<int> ans;
        int i = 0;
        int j = k - 1;
        while (j < nums.size()) {
            if (nums[j] == nums[i] + k - 1) {
                bool res = true;
                for (int x = i + 1; x <= j; x++) {
                    if (nums[x] != nums[x - 1] + 1) {
                        res = false;
                        break;
                    }
                }
                if (!res) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(nums[j]);
                }
            } else {
                ans.push_back(-1);
            }
            i++;
            j++;
        }
        return ans;
    }
};

class Solution3 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param N int整型
     * @param names string字符串vector
     * @return int整型
     */
    int Calc(int N, vector<string> &names) {
        vector<set<string>> ans(names.size() + 1, set<string>());
        for (int i = 0; i < names.size(); i++) {
            vector<string> tem = chaifen(names[i]);
            for (int j = 0; j < tem.size(); j++) {
                ans[i].insert(tem[j]);
            }
            for (int j = 0; j < i; j++) {
                for (int z = 0; z < tem.size(); z++) {
                    if (ans[j].count(tem[z]) && ans[i].count(tem[z])) {
                        ans[j].erase(tem[z]);
                        ans[i].erase(tem[z]);
                    }
                }
            }
        }
        for (int i = 0; i < names.size(); i++) {
            if (ans[i].empty()) {
                return 0;
            }
        }
        return 1;
    }

    vector<string> chaifen(string a) {
        vector<string> ans;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                for (int z = j + 1; z < a.size(); z++) {
                    string tem(1, a[i]);
                    tem += a[j];
                    tem += a[z];
                    ans.push_back(tem);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> tem = {"NEWYORK", "NEWYORK", "NEWARK"};
    cout << (new Solution3)->Calc(3, tem);
    return 0;
}