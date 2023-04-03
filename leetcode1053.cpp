#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        for (int i = arr.size() - 2; i >= 0; i--) {
            for (int j = arr.size() - 1; j > i; j--) {
                if (arr[i] > arr[j] && arr[j] != arr[j - 1]) {
                    swap(arr[j], arr[i]);
                    return arr;
                }
            }
        }
        return arr;
    }
};

int main() {
    return 0;
}