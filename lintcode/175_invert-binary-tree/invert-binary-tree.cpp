/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 16-04-24 18:00
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
    void invertBinaryTree(TreeNode *root) {
        if (!root) return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};