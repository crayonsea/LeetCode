/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
private:
    void inorder(vector<int>& ans, TreeNode *cur) {
        if (!cur) return;
        if (cur->left) inorder(ans, cur->left);
        ans.push_back(cur->val);
        if (cur->right) inorder(ans, cur->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 先 中 后遍历, 是指 root 在遍历中的位置
        // 先序: root, left, right
        // 中序: left, root, right
        // 后序: left, right, root

        vector<int> ans;
        inorder(ans, root);
        
        return ans;
    }
};
// @lc code=end

