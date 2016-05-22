
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int _v=0): val(_v), left(NULL), right(NULL) {}
};

class BST{
public:
    TreeNode* buildBST(int* arr, int l, int r) {
	if(l > r) return NULL;
	int m = l + (r-l) / 2;
	TreeNode* root = new TreeNode(arr[m]);
	root -> left = buildBST(arr, l, m-1);
	root -> right = buildBST(arr, m+1, r);
	return root;
    }

    TreeNode* buildBST(vector<int> arr) {
	const int n = arr.size();
	if(n == 0) return NULL;
	int m = n / 2;
	TreeNode* root = new TreeNode(arr[m]);
	root -> left = buildBST(vector<int>(arr.begin(), arr.begin()+m-1));
	root -> right = buildBST(vector<int>(arr.begin()+m+1, arr.end()));
	return root;
    }
    
    vector<int> inorder(TreeNode *root) {
	vector<int> res;
	inorder_helper(root, res);
	return res;
    }

    void inorder_helper(TreeNode* cur, vector<int> &res) {
	if(!cur) return;
	inorder_helper(cur->left, res);
	res.push_back(cur->val);
	inorder_helper(cur->right, res);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = NULL;
        bool valid =  true;
        inorder_traversal(root, pre, valid);
        return valid;
    }
    
    void inorder_traversal(TreeNode *cur, TreeNode *&pre, bool &valid) {        
        if(!cur) return;
        inorder_traversal(cur->left, pre, valid);
        if(pre && pre -> val >= cur -> val) valid = false;
        pre = cur;
        inorder_traversal(cur->right, pre, valid);
    }

    bool isValidBST1(TreeNode *root) {
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

    bool isValidBST2(TreeNode *root) {
	stack<TreeNode*> stk;
	TreeNode* pre = NULL;
	TreeNode* cur =  root;
	while(stk.size() || cur) {
	    if(cur){
		stk.push(cur);
		cur = cur->left;
	    }
	    else {
		cur = stk.top();
		stk.pop();
		if(pre && pre->val >= cur->val) return false;
		pre = cur;
		cur = cur->right;
	    }
	}
        return true;
    }

    TreeNode* removeNode(TreeNode* root, int value) {
        return helper(root, value);
    }
    
    TreeNode* helper(TreeNode* cur, int value) {
        if(!cur) return NULL;
        TreeNode* l = helper(cur->left, value);
        TreeNode* r = helper(cur->right, value);

	cout << cur->val;        
        if(cur->val == value) {

            if(l) {    
                TreeNode* rr = l;
                while(rr->right) rr = rr->right;
                rr->right = r;
                return l;
            }
            else
                return r;
	}
        return cur;
    }
};

int main() {

    const int n = 5;
    int arr[n] = {1,2,3,4,5};
    vector<int> va(arr, arr+n);
    
    BST bst;
    TreeNode* root = bst.buildBST(arr, 0, n-1);
    vector<int> inorder = bst.inorder(root);

    for(vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it) {
	cout << *it << " ";
    }
    cout << endl;

    Solution sol;
    cout << "ValidBST = " << (sol.isValidBST2(root) ? "Yes" : "No") << endl;
    
    sol.removeNode(root, 2);
    inorder = bst.inorder(root);

    for(vector<int>::iterator it = inorder.begin(); it != inorder.end(); ++it) {
	cout << *it << " ";
    }
    cout << endl;


    return 0;
}
