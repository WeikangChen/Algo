/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 16-04-23 02:00
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int sum = 0;
        int largest = INT_MIN;
        for (auto n : nums) {
            sum = max(sum, 0) + n;
            largest = max(largest, sum);
        }
        return largest;
    }
};
