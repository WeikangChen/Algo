/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-04-25 20:12
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dum(-1);
        dum.next = head;
        ListNode *cur = head;
        while (cur->next) {
            int val = cur->next->val;
            ListNode *pre = &dum;
            while (pre != cur && pre->next->val <= val) pre = pre->next;
            if (pre != cur) {
                ListNode* aft = cur->next;
                cur->next = aft->next;
                aft->next = pre->next;
                pre->next = aft;

            } else 
                cur = cur->next;
        }
        return dum.next;
    }
};