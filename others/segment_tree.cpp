#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;


class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    SegmentTreeNode * build(vector<int>& A) {
        if (A.empty()) return NULL;
        return helper(A, 0, A.size()-1);
    }
    SegmentTreeNode *helper(vector<int> &A, int l, int r) {
	//cout << l << ", " << r << endl;
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
    int query(SegmentTreeNode *root, int start, int end) {
	//cout << "query in [" << root->start << ", " << root->end << "]" << endl;
        if(end < root->start || start > root->end) return INT_MIN;
	if(root->start <= start && end <= root->end) return root->max;
        if(root->start == root->end) return root->max;
        int mid = root->start + (root->end - root->start) / 2;
        int ret = 0;
        if(start <= mid) ret = max(ret, query(root->left, start, end));
        if(end > mid) ret = max(ret, query(root->right, start, end));
        return ret;
    }
};


int main(int argc, char *argv[])
{
    vector<int> va = {1,4,2,3,6,7};
    Solution sol;
    SegmentTreeNode *root = sol.build(va);
    SegmentTreeNode *cur = root;
    stack<SegmentTreeNode*> stk;
    cout << "Preorder Traversal:" << endl;
    while (stk.size() || cur) {
	if (cur) {
	    cout << "\t[" << cur->start << ", " << cur->end << "], max=" << cur->max << endl;
	    stk.push(cur->right);
	    cur = cur->left;
	} else {
	    cur = stk.top();
	    stk.pop();
	}
    }
    int res =  sol.query(root, 3, 5);
    cout << "inquery [1,2] = " << res << endl;
    return 0;
}
