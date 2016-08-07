/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-04-22 14:43
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return helper(root) >= 0;
    }
    
    int helper(TreeNode *cur) {
        if (!cur) return 0;
        int left = helper(cur->left);
        int right = helper(cur->right);
        if (left < 0 || right < 0 || abs(left-right) > 1) return -1;
        return max(left, right) + 1;
    }
};