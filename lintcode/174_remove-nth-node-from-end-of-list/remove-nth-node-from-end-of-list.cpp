/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-05-27 01:41
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dum(-1);
        dum.next = head;
        ListNode *fast = head;
        ListNode *slow = &dum;

        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        if (tmp) slow->next = tmp->next;
        delete tmp;

        return dum.next;
    }
};


