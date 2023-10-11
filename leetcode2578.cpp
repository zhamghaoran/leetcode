#include <bits/stdc++.h>

using namespace std;

int val[100][10];
int main() {
    int a;
    cin >> a;
    for (int i = 1;i <= a;i ++) {
        for (int j = 1;j <= 5;j ++) {
            cin>>val[i][j];
        }

    }
    int now = 0;
    for(int i = 1;i <= 5;i ++) {
        if (val[1][i] == 2) {
            now = i;
            break;
        }
    }
    for (int i = 1;i < a;i ++) {
        int noww = 0;
        for (int j = 1;j < now;j ++) {
            if (val[i][j] == 1) {
                cout<<"L"<<now - j<<" ";
                now = j;
            }
        }
        for (int j = now + 1;j <= 5;j ++) {
            if (val[i][j] == 1) {
                cout<<"R"<<j - now<<" ";
                now = j;
            }
        }
        int tem = 1;
        while (val[i + tem][now] == 1) {
            tem ++;
        }
        cout<<"D"<<tem<<" ";
        i += tem - 1;
    }
    if (now != 5) {
        cout<<"R"<<5 - now<<" "<<endl;
    }
    return 0;
}
/*
3
2 0 0 0 1
0 0 0 0 1
0 0 0 0 0
 *
 */