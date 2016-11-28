#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};
 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

char tree_sp = '_';
char tree_lc = '/';
char tree_rc = '|';


class Solution {
    vector<int> result;

    int recurDepthUtil(TreeNode *cur) {
        if (!cur) return 0;
        return max(recurDepthUtil(cur->left), recurDepthUtil(cur->right)) + 1;
    }

public:
    int print(TreeNode *cur) {
        if (!cur) return 0;
        int l_space = print(cur->left);
        int r_space = print(cur->left);
        return l_space + r_space + 1;
    }
    
    int recurTravlUtil(TreeNode *cur, vector<vector<int>> &res) {
        if (!cur) return 0;
        int l_depth = recurTravlUtil(cur->left, res);
        int r_depth = recurTravlUtil(cur->right, res);
        int depth = max(l_depth, r_depth) + 1;
        if (depth > res.size())
            res.push_back(vector<int>());
        res[depth-1].push_back(cur->val);
        return depth;
    }

    vector<vector<int>> reverseTraversal(TreeNode *root) {
        vector<vector<int>> res;
        recurTravlUtil(root, res);
        return res;
    }
    
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur;
        
        if(!root) return res;
        stk.push(root);
        
        while( !stk.empty() ) {
            cur = stk.top(); stk.pop();
            res.push_back(cur->val);
            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }
        
        reverse(res.begin(), res.end());
        return res;  
    }

    vector<int> postorderTraversal2a(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        TreeNode *pre, *cur;
        stack<TreeNode*> s;
        
        s.push(root);
        pre = NULL;
        
        while(!s.empty()) {
            cur = s.top();
            if(!pre || cur == pre->left || cur == pre->right) {
                if(cur->left) s.push(cur->left);
                else if(cur->right) s.push(cur->right);
            } else {
                if(cur->left == pre && cur->right) {
                    s.push(cur->right);
                } else {                   // On Cases: cur == pre || cur->left == pre || cur->right == pre
                    res.push_back(cur->val);
                    s.pop();
                }
            }
            pre = cur;
        }
        
        return res;
    }


    vector<int> postorderTraversal_IT(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        TreeNode *pre, *cur;
        stack<TreeNode*> s;
        
        pre = NULL;
        s.push(root);

        while(!s.empty()) {
            cur = s.top();
            if(!pre || pre->left == cur || pre->right ==cur) {
                if(cur->left) 
                    s.push(cur->left);
                else if (cur->right)
                    s.push(cur->right);
            } else {
                if(cur->left == pre) {
                    if(cur->right) s.push(cur->right);
                } else {
                    res.push_back(cur->val);
                    s.pop();
                }
            }
            pre = cur;
        }
        
        return res;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        result.clear();
        preorder(root);
        return result;
    }

    void preorder(TreeNode *root) {
        if(root) {
            result.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }

    vector<int> postorderTraversal_R(TreeNode *root) {
        result.clear();
        postorder(root);
        return result;
    }
    
    void postorder(TreeNode *root) {
        if(root) {
            postorder(root->left);
            postorder(root->right);
            result.push_back(root->val);
        }
    }
};

TreeNode* makeBST(int *arr, int start, int end) {
   
    if(start > end) return NULL;
    int mid = (start + end)>>1;

    TreeNode *node = new TreeNode(arr[mid]);
    node->left = makeBST(arr, start, mid-1);
    node->right = makeBST(arr, mid+1, end);

    return node;
}

int main() {

    const int s = 13;
    int myArr1[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    Solution mySol;
    TreeNode * myTree = makeBST(myArr1, 0, s-1);
    ListNode * myList = new ListNode[s];


    for(int i = 0; i < s; i++) {
        myList[i].val = myArr1[i];
        myList[i].next = myList+i+1;
        cout  << myList[i].val << "  ";
    }
    cout << endl;


    vector<int> myvector;
        
    myvector = mySol.preorderTraversal(myTree);
    cout << "Preorder Traversal Recursively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;
    
    myvector = mySol.postorderTraversal_R(myTree);
    cout << "postorder Traversal Recursively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;


    myvector = mySol.postorderTraversal(myTree);
    cout << "postorder Traversal Iteratively:" << endl; 
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        cout  << *it << "  ";
    cout << endl;

    vector<vector<int>> rev_travel = mySol.reverseTraversal(myTree);
    for (auto it = rev_travel.begin(); it != rev_travel.end(); ++it) {
        for(auto is = it->begin(); is != it->end(); ++is) {
            cout << *is << " ";
        }
        cout << endl;
    }
    cout << endl;

    int A = 'A';
    int C = 'C';
    int G = 'G';
    int T = 'T';
    cout << (A & 7) << endl;
    cout << (C & 7) << endl;
    cout << (G & 7) << endl;
    cout << (T & 7) << endl;
    
    return 0;
}
