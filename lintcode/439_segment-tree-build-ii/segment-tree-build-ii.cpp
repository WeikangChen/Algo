/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/segment-tree-build-ii
@Language: C++
@Datetime: 16-05-01 20:13
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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if (A.empty()) return NULL;
        return helper(A, 0, A.size()-1);
    }
    SegmentTreeNode *helper(vector<int> &A, int l, int r) {
        if (l == r) {
            return new SegmentTreeNode(l, l, A[l]);
        } else {
            int m = l + (r - l) / 2;
            SegmentTreeNode *lc = helper(A, l, m);
            SegmentTreeNode *rc = helper(A, m+1, r);
            SegmentTreeNode *cur = new SegmentTreeNode(l, r, max(lc->max, rc->max));
            cur->left = lc;
            cur->right = rc;
            return cur;
        }
    }
};