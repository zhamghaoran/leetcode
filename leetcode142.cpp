#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> sett;
        if (head == nullptr) {
            return nullptr;
        }
        while (head->next != nullptr) {
            if (sett.count(head)) {
                return head;
            }
            sett.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

int main() {
    return 0;
}