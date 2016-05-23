#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        dfs(nums, nums.size()-1, res);
        return res;
    }

    void dfs(vector<int>& nums, int p, vector<vector<int> > &res)
    {
        if(p == nums.size()-1)
        {
            for(int i = 0; i < nums.size(); ++i)
            {
                cout << nums[i];
            }
            cout << endl;
            res.push_back(nums);
            return;
        }

        for(int i = p; i < nums.size(); ++i)
        {
            if(i > p && nums[i] == nums[p]) continue;
            swap(nums[i], nums[p]);
            dfs(nums, p1, res);
            swap(nums[i], nums[p]);
        }
    }
};

int main(int argc, char ** argv)
{
    Solution s;
    int as[] = {1, 2, 3};
    vector<int> vs(as, as + sizeof(as)/sizeof(int));
    s.permuteUnique(vs);

    return 0;
}
