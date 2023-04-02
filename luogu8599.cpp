#include "bits/stdc++.h"

using namespace std;
int a;
int val[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int ans;

int main() {
    cin >> a;
    while (true) {
        int x = 0;
        for (int i = 1; i <= 7; i++) {
            x *= 10;
            x += val[i];
            int y = 0;
            for (int j = i + 1; j <= 8; j++) {
                y *= 10;
                y += val[j];
                int z = 0;
                for (int k = j + 1; k <= 9; k++) {
                    z *= 10;
                    z += val[k];
                }
                if (y % z == 0 && a == x + y / z)
                    ans++;
            }
        }
        next_permutation(val + 1, val + 1 + 9);
        bool pd = false;
        for (int i = 1; i <= 9; i++)
            if (val[i] != i) {
                pd = true;
            }
        if (!pd)
            break;
    }
    cout << ans;
    return 0;
}
