#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {

        return dfs(head, nullptr);
    }

    ListNode *dfs(ListNode *head, ListNode *pre) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            head->next = pre;
            return head;
        }
        ListNode *NewHead = dfs(head->next, head);
        head->next = pre;
        return NewHead;
    }
};

int main() {
    return 0;
}