/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
@Language: C++
@Datetime: 16-05-27 02:14
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> one;
        queue<TreeNode*> que;
        que.push(root);
        int size = 1;
        while (que.size()) {
            TreeNode* cur = que.front();
            que.pop(); size--;
            one.push_back(cur->val);
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            if (size == 0) {
                size = que.size();
                res.push_back(one);
                one.clear();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};