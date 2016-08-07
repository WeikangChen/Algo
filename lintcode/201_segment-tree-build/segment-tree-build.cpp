/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/segment-tree-build
@Language: C++
@Datetime: 16-05-01 20:22
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) return NULL;
        if (start == end) return new SegmentTreeNode(start, end);
        int mid = start + (end - start) / 2;
        SegmentTreeNode *cur = new SegmentTreeNode(start, end);
        cur->left = build(start, mid);
        cur->right = build(mid+1, end);
        return cur;
    }
};