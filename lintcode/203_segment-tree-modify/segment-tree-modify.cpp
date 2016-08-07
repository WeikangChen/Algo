/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/segment-tree-modify
@Language: C++
@Datetime: 16-05-02 03:17
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        if (index < root->start || index > root->end)
            return;
    
        if (root->start == root->end) {
            root->max = value;
            return;
        }
        
        modify(root->left, index, value);
        modify(root->right, index, value);
        
        if (root->left && root->right)
            root->max = max(root->left->max, root->right->max);
    }
};