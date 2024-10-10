#include "bits/stdc++.h"

using namespace std;

class LRUCache {
public:
    struct Node {
        int val;
        int key;
        Node *before;
        Node *after;

        Node() : key(0), val(0), before(nullptr), after(nullptr) {}
    };

    int ca;
    int cnt;
    Node *head;
    Node *tail;
    int val = 0;
    unordered_map<int, int> mapp;
    unordered_map<int, Node *> nodeMap;

    LRUCache(int capacity) {
        head = new Node;
        tail = new Node;
        head->after = tail;
        tail->before = head;
        ca = capacity;
        cnt = 0;
    }

    int get(int key) {
        if (!mapp.count(key) || mapp[key] == -1) {
            return -1;
        }
        Node *node = nodeMap[key];
        node->after->before = node->before;
        node->before->after = node->after;
        node->after = head->after;
        head->after->before = node;
        node->before = head;
        head->after = node;
        return mapp[key];
    }

    void put(int key, int value) {
        if (!mapp.count(key) || mapp[key] == -1) {
            if (cnt == ca) {
                tail = tail->before;
                tail->after = new Node;
                cnt--;
                nodeMap[tail->key] = nullptr;
                mapp[tail->key] = -1;
            }
            Node *node = new Node();
            node->after = new Node();
            node->val = value;
            node->key = key;
            head->after->before = node;
            node->before = head;
            node->after = head->after;
            head->after = node;
            nodeMap[key] = node;
            mapp[key] = value;
            cnt++;
        } else {
            mapp[key] = value;
            nodeMap[key]->val = value;
            nodeMap[key]->key = key;
            Node *node = nodeMap[key];
            node->after->before = node->before;
            node->before->after = node->after;
            node->after = head->after;
            head->after->before = node;
            node->before = head;
            head->after = node;
        }
    }
};

int main() {
    LRUCache *obj = new LRUCache(1);
    obj->get(6);
    obj->get(8);
    obj->put(12, 1);
    obj->get(2);
    obj->put(15, 11);
    obj->put(5, 2);
    obj->put(1, 15);
    obj->put(4, 2);
    obj->get(4);
    obj->put(15, 15);
    return 0;
}