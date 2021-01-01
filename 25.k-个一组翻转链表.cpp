/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        if (!head->next) return head;
        
        vector<ListNode*> pList;
        for (ListNode *p = head; p; p = p->next) pList.push_back(p);
        
        int len = pList.size();
        for (int i = 0; i + k - 1 < len; i += k) {
            for (int j = i + k - 1; j >= i + 1; j--) {
                pList[j]->next = pList[j-1];
            }
        }

        for (int i = 0; i + k - 1 < len; i += k) {
            if (i + k + k - 1 < len) pList[i]->next = pList[i + k + k - 1];
            else if (i + k < len) pList[i]->next = pList[i + k];
            else pList[i]->next = nullptr;
        }
        return pList[k-1];
    }
};
// @lc code=end

