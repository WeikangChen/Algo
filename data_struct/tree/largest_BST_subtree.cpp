#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int LargestBST(TreeNode* root) {
        if(!root) return 0;
        int largest = 0;
        LargestBST_Helper(INT_MIN-1LL, INT_MAX+1LL, root, largest);
        return largest;
    }
    
    int LargestBST_Helper(long long lval, long long rval, TreeNode *cur, int & largest) {
        if(!cur) return 0;

        int left_size = LargestBST_Helper(lval, cur->val, cur->left, largest);
        int right_size = LargestBST_Helper(cur->val, rval, cur->right, largest);

        if(left_size >= 0 && right_size >= 0 && lval < cur->val && cur->val < rval) {
            int cur_size = left_size + right_size +1;
            //cout << "cur size " << cur_size << endl;
            largest = max(largest, cur_size);
            return cur_size;
        }
        return -1;
    }

    TreeNode* Build_Tree(vector<int>& nums, int l, int r)
    {
        if(l > r) return NULL;
        int m = l + (r-l) / 2;
        TreeNode *cur = new TreeNode(nums[m]);
        cur->left = Build_Tree(nums, l, m-1);
        cur->right = Build_Tree(nums, m+1, r);
        return cur;
    }


};

int main(int argc, char ** argv)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int n = sizeof(arr)/sizeof(int);
    vector<int> varr(arr, arr + n);
    
    Solution sol;
    TreeNode *tree = sol.Build_Tree(varr, 0, n-1);
    cout << " The largest sub BST size = " << sol.LargestBST(tree) << endl;
    return 0;
}
