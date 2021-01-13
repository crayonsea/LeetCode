/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool first = true;

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        if (!root->left && !root->right) return root->val == sum;
        if (!root->left && root->right) return hasPathSum(root->right, sum - root->val);
        if (!root->right && root->left) return hasPathSum(root->left, sum - root->val);

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end

