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
    vector<vector<int>> ans = vector<vector<int>>();

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root != nullptr) {
            dfs(root, 0);
        }
        return ans;
    }

    void dfs(TreeNode *root, int dep) {
        if (ans.size() <= dep) {
            ans.emplace_back();
        }
        ans[dep].push_back(root->val);
        if (root->left != nullptr) {
            dfs(root->left, dep + 1);
        }
        if (root->right != nullptr) {
            dfs(root->right, dep + 1);
        }
    }
};

class Solution1 {
public:
    int maxK(vector<int> &nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int j = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (j == k) {
                break;
            }
            sum += nums[i];
            j++;
        }
        return sum;
    }
};

class Solution2 {
public:
    int GameStrategy(vector<vector<int> > &bosses) {
        vector<vector<long long>> dp(bosses.size() + 10, vector<long long>(2, 0));
        dp[0][1] = bosses[0][0];
        for (int i = 1; i < bosses.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (bosses[j][1] < i - j) {
                    dp[i][1] = max(dp[i][1], dp[j][1] + bosses[i][0]);
                }
                dp[i][0] = max(max(dp[j][0], dp[j][1]), dp[i][0]);
            }
        }
        return max(dp[bosses.size() - 1][1], dp[bosses.size() - 1][0]);
    }
};


int main() {
    vector<vector<int>> faq = {{3, 1},
                               {4, 4},
                               {3, 4},
                               {2, 5},
                               {9, 6},
                               {7, 1},
                               {1, 0}};
    cout << (new Solution2)->GameStrategy(faq);
    return 0;
}