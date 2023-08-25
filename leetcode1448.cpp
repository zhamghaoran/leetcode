#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;

    void dfs(TreeNode *root, int maxx) {
        if (root->val >= maxx)
            ans++;
        if (root->left != nullptr) {
            dfs(root->left, max(root->val, maxx));
        }
        if (root->right != nullptr) {
            dfs(root->right, max(root->val, maxx));
        }
    }

    int goodNodes(TreeNode *root) {
        if (root->left != nullptr) {
            dfs(root->left, root->val);
        }
        if (root->right != nullptr) {
            dfs(root->right, root->val);
        }
        return ans + 1;
    }
};

int main() {
    return 0;
}