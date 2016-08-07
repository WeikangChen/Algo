/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/lowest-common-ancestor
@Language: C++
@Datetime: 16-07-22 18:52
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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
    	if (!root) return NULL;
        TreeNode* lc = lowestCommonAncestor(root->left, A, B);
		TreeNode* rc = lowestCommonAncestor(root->right, A, B);

		if (root == A || root == B)
			return root;
		else if (lc && rc)
			return root;
		else if (lc && !rc)
			return lc;
		else if (!lc && rc) 
			return rc;
		return NULL;
    }
};