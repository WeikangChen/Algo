#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        //sort(nums.begin(), nums.end());
        dfs(nums, nums.size()-1, res);
        return res;
    }

    void dfs(vector<int>& nums, int p, vector<vector<int> > &res)
    {
        if(p == -1) {
            res.push_back(nums);
            return;
        }
        for(int i = p; i < nums.size(); ++i) {
            if(i > p && nums[i] == nums[p]) break;
            swap(nums[i], nums[p]);
            dfs(nums, p-1, res);
            swap(nums[i], nums[p]);
        }
    }

    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique1(vector<int> &num) {
        //sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

int main(int argc, char ** argv)
{
    Solution s;
    int as[] = {2, 1, 2};
    vector<int> vs(as, as + sizeof(as)/sizeof(int));
    vector<vector<int>> res = s.permuteUnique1(vs);
    for (auto &one : res) {
        for (auto &n : one) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
