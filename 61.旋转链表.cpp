/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;

        int len = 0;
        ListNode* tail = nullptr;
        for (ListNode* p = head; p; p = p->next, len++) if (!p->next) tail = p;
        tail->next = head;

        int s = len - 1 - k % len, cur = 0;
        for (ListNode* p = head; p; p = p->next, cur++) if (cur == s) {
            head = p->next;
            p->next = nullptr;
        }
        
        return head;
    }
};
// @lc code=end

