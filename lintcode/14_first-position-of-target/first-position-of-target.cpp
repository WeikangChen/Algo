/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-04-20 16:31
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int l = 0;
        int r = array.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (array[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if (array[l] == target)
            return l;
        return -1;
    }
};