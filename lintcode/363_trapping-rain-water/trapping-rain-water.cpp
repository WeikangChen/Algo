/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: C++
@Datetime: 16-07-22 00:15
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if (heights.empty()) return 0;
        const int n =  heights.size();
        int res = 0;
        int l_max = heights[0];
        int r_max = heights[n-1];
        int l = 0;
        int r = n-1;
        while (l <= r) {
            l_max = max(l_max, heights[l]);
            r_max = max(r_max, heights[r]);
            if (heights[l] < heights[r])
                res += min(l_max, r_max) - heights[l++];
            else 
                res += min(l_max, r_max) - heights[r--];
        }
        return res;
    }
};