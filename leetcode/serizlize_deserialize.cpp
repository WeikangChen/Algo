#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize1(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        string res;
        while(stk.size() || cur)
        {
            if(cur) {
                res += to_string(cur->val) + " ";
                stk.push(cur->right);
                cur = cur->left;
            } else {
                res += "# ";
                cur = stk.top();
                stk.pop();
            }
            
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize1(string data) {
        stringstream ss(data);
        string one;
        while(ss >> one) {
            if(one == "#") {
            }
                
        }
        
        return NULL; 
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
    
private:    
    void serialize(TreeNode* cur, ostringstream &oss)
    {
        if(cur) {
            oss << (cur->val) << ' ';
            serialize(cur->left, oss);
            serialize(cur->right, oss);
        }
        else {
            oss << "# ";
        }
    }
    
    TreeNode* deserialize(istringstream &iss)
    {
        string one;
        iss >> one;
        if(one.empty() || one == "#" ) return NULL;
        TreeNode* cur = new TreeNode(stoi(one));
        cur->left = deserialize(iss);
        cur->right = deserialize(iss);
        return cur;
    }

    TreeNode* build(vector<int>& nums, int l, int r)
    {
        if(l > r) return NULL;
        int m = l + (r-l) / 2;
        TreeNode *cur = new TreeNode(nums[m]);
        cur->left = build(nums, l, m-1);
        cur->right = build(nums, m+1, r);
        return cur;
    }

};

int main(int argc, char ** argv)
{
    int arr[] = {1,2,3,4};//,5,6,7,8,9};
    vector<int> varr(arr, arr+sizeof(arr)/sizeof(int));
    Codec sol;
    TreeNode *tree = sol.sortedArrayToBST(varr);
    cout << sol.serialize(tree) << endl;
    cout << sol.serialize1(tree) << endl;
    return 0;
}
