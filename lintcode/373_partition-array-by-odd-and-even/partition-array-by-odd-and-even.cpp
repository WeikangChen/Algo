/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-05-14 18:48
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            while (l < r && (nums[l] & 1)) l++;
            while (l < r && !(nums[r] & 1)) r--;
            if (l < r) swap(nums[l], nums[r]);
        }
    }
};