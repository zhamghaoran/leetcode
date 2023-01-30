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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        auto head = list1;
        auto faq = list1;
        for (int i = 0;i < a - 1;i ++) {
            head = head->next;
        }
        for (int i = 0;i <= b;i ++)
            faq = faq->next;
        auto qaq = list2;
        head->next = list2;
        while (qaq->next != nullptr) {
            qaq = qaq->next;
        }
        qaq->next = faq;
        return list1;
    }
};

int main() {
    return 0;
}