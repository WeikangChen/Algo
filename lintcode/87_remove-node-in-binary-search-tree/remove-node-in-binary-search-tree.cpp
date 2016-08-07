/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-node-in-binary-search-tree
@Language: C++
@Datetime: 16-04-17 19:52
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */

    TreeNode* removeNode(TreeNode* root, int value) {
        return helper(root, value);
    }
    
    TreeNode* helper(TreeNode* cur, int value) {
        if(!cur) return NULL;
        TreeNode* l = helper(cur->left, value);
        TreeNode* r = helper(cur->right, value);
        
        if(cur->val == value) {
            delete cur;
            if(l) {
                TreeNode* rr = l;
                while(rr->right) rr = rr->right;
                rr->right = r;
                return l;
            }
            else
                return r;
	    }
	    cur -> left = l;
	    cur -> right = r;
        return cur;
    }
};