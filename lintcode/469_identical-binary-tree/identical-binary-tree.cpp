/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/identical-binary-tree
@Language: C++
@Datetime: 16-04-23 04:02
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (a && b && a->val == b->val 
        && isIdentical(a->left, b->left)
        && isIdentical(a->right, b->right)) return true;
        return false;
    }
};