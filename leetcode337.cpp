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
    pair<int, int> dfs(TreeNode *x) {
        pair<int,int> ans;
        ans.first = x->val;
        if (x->left != nullptr) {
            auto ans1 = dfs(x->left);
            ans.first += ans1.second;
            ans.second += max(ans1.first,ans1.second);
        }
        if (x->right!= nullptr) {
            auto ans2 = dfs(x->right);
            ans.first += ans2.second;
            ans.second += max(ans2.first,ans2.second);
        }
        cout<<x->val<<" "<<ans.first<<" "<<ans.second;
        return ans;
    }

    int rob(TreeNode *root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    return 0;
}