/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 16-04-17 19:01
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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = NULL;
        return inorder_helper(root, pre);
    }
    
    bool inorder_helper(TreeNode *cur, TreeNode *&pre) {        
        if(!cur) return true;
        if(!inorder_helper(cur->left, pre)) return false;
        if(pre && pre -> val >= cur -> val) return false;
        pre = cur;
        return inorder_helper(cur->right, pre);
    }
};