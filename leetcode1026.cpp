#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for a binary tree Node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int ans;
    void dfs(TreeNode *root,int maxx,int minn) {
        int x = root->val;
        ans = max(ans, abs(maxx - x));
        ans = max(ans, abs(minn - x));
        if (root->left != nullptr) {
            dfs(root->left,max(maxx,x),min(minn,x));
        }
        if (root->right != nullptr) {
            dfs(root->right, max(maxx,x),min(minn,x));
        }
    }
    int maxAncestorDiff(TreeNode *root) {
        ans = -0x3f3f3f3f;
        dfs(root,root->val,root->val);
        return ans;
    }
};

int main() {

    return 0;
}