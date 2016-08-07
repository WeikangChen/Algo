/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-tree-serialization
@Language: C++
@Datetime: 16-05-03 15:17
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

    void serialize(TreeNode *cur, ostringstream &oss) {
        if (cur) {
            oss << cur->val << " ";
            serialize(cur->left, oss);
            serialize(cur->right, oss);
        }
        else {
            oss << "# ";
        }
    }
    
    TreeNode* deserialize(istringstream &iss) {
        string sval;
        iss >> sval;
        TreeNode *cur = NULL;
        if(sval.size() && sval != "#") {
            cur = new TreeNode(stoi(sval));
            cur->left = deserialize(iss);
            cur->right = deserialize(iss);
        }
        return cur;
        
    }
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
};
