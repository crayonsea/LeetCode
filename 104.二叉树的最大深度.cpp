/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
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
    int maxdeep(TreeNode *root, int cnt) {
        if (!root) return cnt;
        else return max(maxdeep(root->left, cnt + 1), maxdeep(root->right, cnt + 1));
    }

public:
    int maxDepth(TreeNode* root) {
        return maxdeep(root, 0);
    }
};
// @lc code=end

