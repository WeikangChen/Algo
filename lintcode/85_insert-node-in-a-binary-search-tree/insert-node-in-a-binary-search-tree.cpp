/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/insert-node-in-a-binary-search-tree
@Language: C++
@Datetime: 16-04-24 17:56
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!node) return root;
        if (!root) return node;
        helper(root, node);
        return root;
    }
    void helper(TreeNode* cur, TreeNode *node) {
        if (node->val > cur->val) {
            if (!cur->right)
                cur->right = node;
            else
                helper(cur->right, node);
        } else {
            if (!cur->left)
                cur->left = node;
            else
                helper(cur->left, node);
        }
    }
};