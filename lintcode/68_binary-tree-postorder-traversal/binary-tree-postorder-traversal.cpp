/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-05-14 18:30
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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (stk.size() || cur) {
            if (cur) {
                res.push_back(cur->val);
                if (cur->left) stk.push(cur->left);
                cur = cur->right;
            } else {
                cur = stk.top();
                stk.pop();
            }
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};