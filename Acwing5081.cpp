#include "bits/stdc++.h"

using namespace std;

int main() {
    int a;
    cin >> a;
    map<vector<vector<char>>, int> mapp;
    for (int i = 1; i <= a; i++) {
        vector<vector<char>> qaq(9, vector<char>(9));
        for (int j = 1; j <= 8; j++) {
            for (int z = 1; z <= 8; z++) {
                cin>>qaq[j][z];
            }
        }
        mapp[qaq] ++;
        cout<<mapp[qaq]<<endl;
    }
    return 0;
}