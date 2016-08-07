/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subsets
@Language: C++
@Datetime: 16-04-24 18:42
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        vector<int> one;
        helper(nums, 0, nums.size(), one, res);
        return res;
    }
    void helper(vector<int> &nums, int p, int n, vector<int> &one, vector<vector<int> > &res) {
        res.push_back(one);
        for (int i = p; i < n; ++i) {
            one.push_back(nums[i]);
            helper(nums, i+1, n, one, res);
            one.pop_back();
        }
    }
};