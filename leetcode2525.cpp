#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool a = false;
        bool b = false;
        if ((length >= 10000 || width >= 10000 || height >= 10000) || ((long long)length * (long long)width * (long long)height) >= 1000000000)
            a = true;
        if (mass >= 100) {
            b = true;
        }
        if (a && b) {
            return "Both";
        }
        if (!a && !b) {
            return "Neither";
        }
        if (a) {
            return "Bulky";
        }
        return "Heavy";
    }

};

int main() {

    return 0;
}