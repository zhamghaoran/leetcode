#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        scanf("%d", &x);
        vector<int> val;
        int qaq;
        for (int i = 1; i <= x; i++) {
            scanf("%d", &qaq);
            val.push_back(qaq);
        }
        stack<int> faq;
        bool succ = true;
        for (int i = 0; i < x; i++) {
            if (val[i] == 1) {
                faq.push(i);
            } else if (faq.size() < 2) {
                succ = false;
                break;
            } else {
                int x1 = faq.top();
                faq.pop();
                int x2 = faq.top();
                faq.pop();
                faq.push(x1 + x2);
            }
        }
        if (!succ) {
            cout << "-1" << endl;
            continue;
        }
        int num = faq.size();
        int sum = 0;
        while (!faq.empty()) {
            sum += faq.top();
            faq.pop();
        }
        int gcd = __gcd(sum, num);
        cout << sum / gcd << " " << num / gcd << endl;
    }
    return 0;
}