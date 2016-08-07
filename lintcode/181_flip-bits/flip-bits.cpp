/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-04-21 19:51
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int x = a ^ b;
        int cnt = 0;
        while (x) {
            x &= (x-1);
            cnt++;
        }
        return cnt;
    }
};