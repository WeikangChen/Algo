/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/minimum-size-subarray-sum
@Language: C++
@Datetime: 16-04-22 19:05
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        const int n = nums.size();
        int win_min = n+1;
        int sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            sum += nums[i];
            while (sum >= s) {
                win_min = min(win_min, i-j+1);
                sum -= nums[j++];
            }
        }
        return (win_min < n+1 ? win_min : -1);
    }
};