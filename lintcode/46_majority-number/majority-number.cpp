/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-04-29 15:16
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        if (nums.empty()) return 0;
        int majority, occurs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (occurs == 0)
                majority = cur;
            if (cur == majority)
                occurs++;
            else
                occurs--;
        }
        return majority;
    }
};
