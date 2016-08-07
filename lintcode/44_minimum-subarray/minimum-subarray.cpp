/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-05-14 19:25
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int sum = 0;
        int res = INT_MAX;
        for (auto &n : nums) {
            sum = min(sum, 0) + n;
            res = min(res, sum);
        }
        return res;
    }
};
