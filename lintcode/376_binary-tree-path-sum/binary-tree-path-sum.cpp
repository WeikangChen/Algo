/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-path-sum
@Language: C++
@Datetime: 16-07-22 19:08
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<int> one;
        vector<vector<int>> res;
        util(root, target, one, res);
        return res;
    }
    
    void util(TreeNode *cur, int remain, vector<int> &one, vector<vector<int>> &res) {
        if (!cur) return;
        
        one.push_back(cur->val);
        if (!cur->left && !cur->right) {
            if (remain == cur->val) res.push_back(one);
        } else {
            util(cur->left, remain - cur->val, one, res);
            util(cur->right, remain - cur->val, one, res);
        }
        one.pop_back();
        
    }
};