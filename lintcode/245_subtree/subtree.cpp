/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 16-05-01 15:08
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (!T2) return true;
        if (!T1) return false;
        string preorder1, preorder2;
        string inorder1, inorder2;
        preorderTraversal(T1, preorder1);
        preorderTraversal(T2, preorder2);
        inorderTraversal(T1, inorder1);
        inorderTraversal(T2, inorder2);
        return preorder1.find(preorder2) != string::npos &&
            inorder1.find(inorder2) != string::npos;
    }
    void preorderTraversal(TreeNode *cur, string &preorder) {
        if (cur) {
            preorder.append(to_string(cur->val) + ",");
            preorderTraversal(cur->left, preorder);
            preorderTraversal(cur->right, preorder);
        } else {
          preorder.push_back('$');
        }
    }
    void inorderTraversal(TreeNode *cur, string &inorder) {
        if (cur) {
            inorderTraversal(cur->left, inorder);
            inorder.append(to_string(cur->val) + ",");
            inorderTraversal(cur->right, inorder);
        } else {
          inorder.push_back('$');
        }
    }
};