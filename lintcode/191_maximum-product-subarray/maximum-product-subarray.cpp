/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 16-07-12 00:51
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int cur_min = nums[0];
        int cur_max = nums[0];
        int res = cur_max;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            if (num < 0) 
                swap(cur_min, cur_max);
            cur_min = min(cur_min * num, num);
            cur_max = max(cur_max * num, num);
            res = max(res, cur_max);
        }
        
        return res;
    }
};