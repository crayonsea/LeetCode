/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    void level(TreeNode *root, vector<vector<int>>& ans, int d) {
        if (!root) return;
        
        if (ans.size() <= d) {
            ans.resize(d + 1);
        }
        ans[d].push_back(root->val);
        
        level(root->left, ans, d + 1);
        level(root->right, ans, d + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        level(root, ans, 0);
        reverse(begin(ans), end(ans));
        return ans;
    }
};
// @lc code=end

