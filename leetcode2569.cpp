#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        int a = nums1.size();
        int num1 = 0;
        vector<int> num(a + 10, 0);
        for (int i = 0; i < nums1.size(); i++) {
            num[i + 1] = num[i];
            if (nums1[i] == 1) {
                num1++;
                num[i + 1]++;
            }
        }
        long long sum = 0;
        long long add = 0;
        vector<long long> ans;
        for (int i: nums2) {
            sum += i;
        }
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {
                int l = queries[i][1] + 1;
                int r = queries[i][2] + 1;
                int cha = num[r] - num[l - 1];
                num1 = num1 - cha + r - l + 1 - cha;
            } else if (queries[i][0] == 2) {
                add += num1 * queries[i][1];
            } else {
                ans.push_back(sum + add);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> faq = {1, 1, 1, 0, 1, 0, 1, 1, 0};
    vector<int> qaq = {35, 29, 21, 34, 8, 48, 22, 43, 37};
    vector<vector<int>> f = {{1, 4,  7},
                             {3, 0,  0},
                             {2, 27, 0},
                             {3, 0,  0},
                             {1, 0,  3},
                             {3, 0,  0},
                             {2, 6,  0},
                             {1, 3,  8},
                             {2, 13, 0},
                             {3, 0,  0},
                             {3, 0,  0},
                             {3, 0,  0},
                             {2, 2,  0},
                             {2, 28, 0},
                             {3, 0,  0},
                             {3, 0,  0},
                             {2, 25, 0},
                             {3, 0,  0},
                             {3, 0,  0},
                             {1, 2,  5}};
    vector<long long> ans = (new Solution)->handleQuery(faq, qaq, f);
    return 0;
}