/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 16-07-23 16:45
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na = 0;
        int nb = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA) {na++; curA = curA->next;}
        while (curB) {nb++; curB = curB->next;}
        
        curA = headA;
        curB = headB;
        while (na > nb) {curA = curA->next; na--;}
        while (na < nb) {curB = curB->next; nb--;}
        
        while (curA) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};