/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list
@Language: C++
@Datetime: 16-07-22 19:35
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        DoublyListNode dum(-1);
        DoublyListNode *d_cur = &dum;
        DoublyListNode *d_pre = NULL;
        while (stk.size() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top(); stk.pop();
                d_pre = d_cur;
                d_cur->next = new DoublyListNode(cur->val);
                d_cur = d_cur->next;
                d_cur->prev = d_pre;
                cur = cur->right;
            }
        }
        return dum.next;
    }
};


