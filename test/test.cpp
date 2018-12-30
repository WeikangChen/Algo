#include <iostream>
#include <vector>
#include <set>

using namespace std;

class A
{
  public:
    void fun()
    {
        delete this;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int min_diff;
    set<int> mp_1;
    set<int> mp_2;
public:
    int getMinimumDifference(TreeNode* root) {
        min_diff = numeric_limits<int>::max();
        mp_1.clear();
        mp_2.clear();
        mp_1.emplace(root->val);
        mp_2.emplace(-root->val);
        traversal(root->left);
        traversal(root->right);
        return min_diff;
    }
    
    void traversal(TreeNode* cur) {
        if (!cur) return;
        int v = cur->val;
        auto it1 = mp_1.lower_bound(v);
        auto it2 = mp_2.lower_bound(v);
        int cur_min = min(abs(*it1 - v), abs(*it2 + v));
        min_diff = min(min_diff, cur_min);
        mp_1.emplace(v);
        mp_2.emplace(-v);
        traversal(cur->left);
        traversal(cur->right);
    }
};

int main()
{
  /* Following is Valid */
  A *ptr = new A;
  ptr->fun();

  int x{};
  cout << x << endl;
/* 
  A b;
  b.fun();
 */
  return 0;
}
