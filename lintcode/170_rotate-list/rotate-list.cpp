/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 16-07-12 02:15
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 1;
        ListNode *tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }
        
        k %= n;
        k = n-k;
        ListNode dum(-1);
        dum.next = head;
        ListNode *cur = &dum;
        while (k--) cur = cur->next;
        if (cur->next != head) {
            tail->next = dum.next;
            dum.next = cur->next;
            cur->next = NULL;
        }
        
        return dum.next;
    }
};