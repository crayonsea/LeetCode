/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        
        vector<ListNode*> pList;
        for (ListNode *p = head; p; p = p->next) pList.push_back(p);
        
        int len = pList.size();
        for (int i = 0; i < len; i += 2) {
            ListNode *cur = pList[i];
            if (cur->next) cur->next->next = cur;
        }

        for (int i = 0; i < len; i += 2) {
            ListNode *cur = pList[i];
            if (i + 3 < len) cur->next = pList[i+3];
            else if (i + 2 < len) cur->next = pList[i+2];
            else cur->next = nullptr;
        }
        return pList[1];
    }
};
// @lc code=end

