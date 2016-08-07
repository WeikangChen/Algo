/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 16-04-24 13:24
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (!head) return NULL;
        ListNode *pre = head;
        ListNode *cur = head -> next;
        while (cur) {
            ListNode *aft = cur->next;
            cur->next = pre;
            pre = cur;
            cur = aft;
        }
        head->next = NULL;
        return pre;
    }
};
