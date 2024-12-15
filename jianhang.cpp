#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector
     * @return long长整型
     */
    long long solve(vector<int> &arr) {
        int i, j;
        long long ans = 0;
        i = 0;
        j = arr.size() - 1;
        while (i < j) {
            if (arr[i] != arr[j]) {
                if (arr[i] < arr[j]) {
                    long long add = arr[j] - arr[i];
                    arr[i] = arr[j];
                    arr[i + 1] += add;
                    ans += add;
                } else {
                    long long add = arr[i] - arr[j];
                    arr[j] = arr[i];
                    arr[j - 1] += add;
                    ans += add;
                }
            }
            i++;
            j--;
        }
        if (arr.size() % 2 == 0) {
            if (arr[arr.size() / 2] != arr[arr.size() / 2 - 1]) {
                return -1;
            }
        }
        return ans;
    }
};