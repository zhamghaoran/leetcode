#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    struct node {
        TreeNode *tree;
        int maxx;
    };

    node *dfs(TreeNode *root, int depth) {
        if (root == nullptr) {
            return new node{nullptr, depth};
        }
        auto a1 = dfs(root->left, depth + 1);
        auto a2 = dfs(root->right, depth + 1);
        cout<<root->val<<" "<<a1->maxx<<" "<<a2->maxx<<endl;
        if (a1->maxx > a2->maxx) {
            return new node{a1->tree, a1->maxx};
        } else if (a1->maxx < a2->maxx) {
            return new node{a2->tree, a2->maxx};
        } else {
            return new node{root, a1->maxx};
        }
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        return dfs(root, 0)->tree;
    }
};

int main() {
    TreeNode *node = new TreeNode;
    return 0;
}