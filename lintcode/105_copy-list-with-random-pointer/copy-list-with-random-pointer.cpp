/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 16-07-12 03:00
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> hs;
        RandomListNode* cp_head = new RandomListNode(head->label);
        RandomListNode* cur = head->next;
        RandomListNode* cp_cur = cp_head;
        hs[head] = cp_head;
        while(cur) {
            cp_cur->next = new RandomListNode(cur->label);
            cp_cur = cp_cur->next;
            hs[cur] = cp_cur;
            cur = cur->next;
        }
        cp_cur = cp_head;
        cur = head;
        while (cur) {
            if (cur->random) cp_cur->random =hs[cur->random];
            cp_cur = cp_cur->next;
            cur = cur->next;
        }
        return cp_head;
    }
};