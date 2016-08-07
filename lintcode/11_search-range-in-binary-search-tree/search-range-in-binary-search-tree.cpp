/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: C++
@Datetime: 16-04-24 21:09
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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (stk.size() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                int val = cur->val;
                if (val > k2) break;
                if (val >= k1) res.push_back(val);
                cur = cur ->right;
            }
        }
        return res;
    }
};