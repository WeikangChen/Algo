/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-04-24 13:54
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
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head; 
        ListNode dum(-1);
        ListNode *pre, *cur, *aft; 
        dum.next = head;
        pre = &dum;
        cur = head;
        while (cur && cur->next) {
            aft = cur->next;
            cur->next = aft->next;
            aft->next = pre->next;
            pre->next = aft;
            pre = cur;
            cur = cur->next;
        }
        return dum.next;
    }
};