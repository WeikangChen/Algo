/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 16-04-24 18:52
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<vector<int> > res;
        vector<int> one;
        vector<int> nums(S);
        sort(nums.begin(), nums.end());
        helper(nums, 0, nums.size(), one, res);
        return res;
    }
    void helper(const vector<int> &nums, int p, int n, vector<int> &one, vector<vector<int> > &res) {
        res.push_back(one);
        for (int i = p; i < n; ++i) {
            if (i > p && nums[i] == nums[i-1]) continue;
            one.push_back(nums[i]);
            helper(nums, i+1, n, one, res);
            one.pop_back();
        }
    }
};
