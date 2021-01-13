/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    void reverseTree(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);   
        reverseTree(root->left);
        reverseTree(root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p && !q) || (!p && q)) return false;
        if (!p && !q) return true;
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        reverseTree(root->left);
        return isSameTree(root->left, root->right);
    }
};
// @lc code=end

