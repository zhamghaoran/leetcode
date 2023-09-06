#include "bits/stdc++.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        vector<int> ans;
        while (head != nullptr) {
            ans.push_back(head->val);
            head = head->next;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    return 0;
}