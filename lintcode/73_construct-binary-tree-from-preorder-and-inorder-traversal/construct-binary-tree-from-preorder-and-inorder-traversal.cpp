/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 16-05-04 01:15
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
private:
    unordered_map<int, int> indexMap;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        const int n = inorder.size();
        for (int i = 0; i < n; ++i) indexMap[inorder[i]] = i;
        return util(preorder, inorder, 0, 0, n-1);
    }
    
    TreeNode *util(vector<int> &preorder, vector<int> &inorder, int pl, int l, int r) {
        if (l > r) return NULL;
        int val = preorder[pl];
        int m = indexMap[val];
        TreeNode* cur = new TreeNode(val);

        cur->left = util(preorder, inorder, pl+1, l, m-1);
        cur->right = util(preorder, inorder, pl+m-l+1, m+1, r);
        return cur;
    }
};