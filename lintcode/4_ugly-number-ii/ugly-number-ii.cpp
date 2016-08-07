/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 16-05-04 01:57
*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int id2, id3, id5;
        id2 = id3 = id5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = min(dp[id2]*2, min(dp[id3]*3, dp[id5]*5));
            dp[i] = tmp;
            if (tmp == dp[id2] * 2) id2++;
            if (tmp == dp[id3] * 3) id3++;
            if (tmp == dp[id5] * 5) id5++;
        }
        return dp[n-1];
    }
};