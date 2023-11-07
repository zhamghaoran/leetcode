#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        if (citations.size() == 1) {
            return min(1, citations[0]);
        }
        int l = 0;
        int r = max(citations[citations.size() - 1], int(citations.size()));
        while (l < r) {
            int mid = (l + r) >> 1;
            int x = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            if (x >= citations.size()) x = -0x3f3f3f3f;
            if (x >= mid) {
                l = mid + 1;
            } else r = mid;
        }
        return max(0, l - 1);
    }
};

class Solution1 {
public:
    int hIndex(vector<int> &citations) {
        // 在区间 [left, right] 内询问
        int n = citations.size();
        int left = 1;
        int right = n;
        while (left <= right) { // 区间不为空
            // 循环不变量：
            // left-1 的回答一定为「是」
            // right+1 的回答一定为「否」
            int mid = (left + right) / 2; // left+(right-left)/2
            // 引用次数最多的 mid 篇论文，引用次数均 >= mid
            if (citations[n - mid] >= mid) {
                left = mid + 1; // 询问范围缩小到 [mid+1, right]
            } else {
                right = mid - 1; // 询问范围缩小到 [left, mid-1]
            }
        }
        // 循环结束后 right 等于 left-1，回答一定为「是」
        // 根据循环不变量，right 现在是最大的回答为「是」的数
        return right;
    }
};


int main() {
    vector<int> faq = {0, 0};
    cout << (new Solution)->hIndex(faq);
    return 0;
}