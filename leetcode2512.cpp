#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int>
    topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report,
                vector<int> &student_id, int k) {
        set<string> posi(positive_feedback.begin(), positive_feedback.end());
        set<string> nega(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int, int>> faq;
        for (int i = 0; i < report.size(); i++) {
            vector<string> ss = splitStringBySpace(report[i]);
            int sum = 0;
            std::for_each(ss.begin(), ss.end(), [&](auto s) -> void {
                if (posi.count(s)) {
                    sum += 3;
                } else if (nega.count(s)) {
                    sum -= 1;
                }
            });
            cout<<sum<<endl;
            faq.emplace_back(sum, student_id[i]);
        }
        sort(faq.begin(), faq.end(), [&](auto a, auto b) -> bool {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(faq[i].second);
        }
        return ans;
    }

    vector<string> splitStringBySpace(const string str) {
        vector<string> result;
        istringstream iss(str);
        string token;

        while (getline(iss, token, ' ')) {
            result.push_back(token);
        }

        return result;
    }
};

int main() {
    return 0;
}