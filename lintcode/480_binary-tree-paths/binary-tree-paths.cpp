/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-05-14 18:26
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> one;
        dfs(root, one, res);
        return res;
    }
    void dfs(TreeNode* cur, vector<int> &one, vector<string> &res) {
        if (!cur) return;
        one.push_back(cur->val);
        if (!cur->left && !cur->right) {
            res.push_back(join(one));
        } else {
            dfs(cur->left, one, res);
            dfs(cur->right, one, res);
        }
        one.pop_back();
    }
    string join(vector<int> one) {
        ostringstream oss;
        const int n = one.size();
        for (int i = 0; i < n-1; ++i)
            oss << one[i] << "->";
        oss << one[n-1];
        return oss.str();
    }
};