/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 16-07-12 03:17
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *l1 = head;
        ListNode *l2 = reverse(slow->next);
        slow->next = NULL;
        
        merge(l1, l2);
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *aft;
        while (cur) {
            aft = cur->next;
            cur->next = pre;
            pre = cur;
            cur = aft;
        }
        return pre;
    }
     
    void merge(ListNode *l1, ListNode *l2) {
        while (l1 && l2) {
            ListNode* n1 = l1->next;
            ListNode* n2 = l2->next;
            l1->next = l2;
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
    }
};


