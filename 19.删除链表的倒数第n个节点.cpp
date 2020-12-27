/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len, pos, cur = 0;
        ListNode* p = head;

        for (len = 0; p; p = p->next) len++;
        pos = len - n;

        if (pos == 0) return head->next;
        
        for (cur = 1, p = head; p; p = p->next, cur++) {
            if (cur == pos) {
                p->next = p->next->next;
                break;
            }
        }

        return head;
    }
};
// @lc code=end

