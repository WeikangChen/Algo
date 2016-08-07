/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-04-20 14:33
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        int car = 0;
        ListNode dum(-1);
        ListNode *cur = &dum;
        while (l1 || l2) {
            int tmp = car;
            if (l1) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                tmp += l2->val;
                l2 = l2->next;
            }
            car = tmp / 10;
            cur->next = new ListNode(tmp%10);
            cur = cur->next;
        }
        if (car) cur->next = new ListNode(1);
        return dum.next;
    }
};