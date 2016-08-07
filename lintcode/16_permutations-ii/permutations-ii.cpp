/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/permutations-ii
@Language: C++
@Datetime: 16-05-04 20:44
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > res;
        util(nums, nums.size()-1, nums.size(), res);
        return res;
    }
    
    void util(vector<int> &nums, int p, int n, vector<vector<int> > &res) {
        if (p == -1) {
            res.push_back(nums);
            return;
        }

        for (int i = p; i < n; ++i) {
            if (i != p && nums[p] == nums[i]) break;
            swap(nums[p], nums[i]);
            util(nums, p-1, n, res);
            swap(nums[p], nums[i]);
        }
    }
};