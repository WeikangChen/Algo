/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-05-03 17:37
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode dum1(-1);        
        ListNode dum2(-1);
        ListNode *pre1 = &dum1;
        ListNode *pre2 = &dum2;
        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                pre1->next = cur;
                pre1 = cur;
            } else {
                pre2->next = cur;
                pre2 = cur;
            }
            cur = cur->next;
        }
        
        pre1->next = dum2.next;
        pre2->next = NULL;
        return dum1.next;
    }
};


