/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 16-05-04 01:19
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
private:
    unordered_map<int, int> indexMap;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        const int n = inorder.size();
        for (int i = 0; i < n; ++i) indexMap[inorder[i]] = i;
        return util(inorder, postorder, n-1, 0, n-1);
    }
    
    TreeNode *util(vector<int> &inorder, vector<int> &postorder, int pr, int l, int r) {
        if (l > r) return NULL;
        int val = postorder[pr];
        int m = indexMap[val];
        TreeNode* cur = new TreeNode(val);

        cur->left = util(inorder, postorder, pr-r+m-1, l, m-1);
        cur->right = util(inorder, postorder, pr-1, m+1, r);
        return cur;
    }
};