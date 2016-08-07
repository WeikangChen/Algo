/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-04-24 17:48
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
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        TreeNode *pre = NULL;
        helper(root, pre);
    }
    
    void helper(TreeNode *cur, TreeNode *&pre) {
        if (!cur) return;
        helper(cur->right, pre);
        helper(cur->left, pre);
        cur->right = pre;
        cur->left = NULL;
        pre = cur;
    }
};