/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-07-15 20:43
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        queue<ListNode*> q;
        for (auto l: lists) {
            q.push(l);
        }
        while (q.size() > 1) {
            ListNode *l1 = q.front(); q.pop();
            ListNode *l2 = q.front(); q.pop();
            q.push(mergeTwoLists(l1, l2));
        }
        return q.front();
    }
    
    ListNode *mergeTwoLists(ListNode* l1, ListNode*l2) {
        ListNode dum(-1);
        ListNode *cur = &dum;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dum.next;
    }
};


