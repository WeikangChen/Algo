/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 16-05-01 19:43
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        int l = 0, i = 1;
        while(i < n)
        {
            int pre = nums[l];
            nums[++l] = nums[i++];
            while(i < n && nums[i] == pre) i++;
        }
        return l+1;
    }
};