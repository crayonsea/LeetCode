/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addon = 0, sum = 0, value = 0;
        ListNode *x = l1, *y = l2;
        ListNode *ans = nullptr, *cur, *pre;

        while (x || y || addon) {
            int a = x? x->val: 0;
            int b = y? y->val: 0;
            
            sum = a + b + addon;
            value = sum % 10;
            addon = sum / 10;

            cur = new ListNode(value);

            if (!ans) ans = cur;
            else pre->next = cur;

            pre = cur;

            // inc
            x = x? x->next: nullptr;
            y = y? y->next: nullptr;
        }

        return ans;
    }
};
// @lc code=end

