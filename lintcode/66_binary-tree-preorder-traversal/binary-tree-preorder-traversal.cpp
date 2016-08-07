/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-04-24 16:42
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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (stk.size() || cur) {
            if (cur) {
                res.push_back(cur->val);
                if (cur->right) stk.push(cur->right);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
        return res;
    }
};
