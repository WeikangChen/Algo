/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 16-05-04 01:49
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        while (b) {
            int car = a & b;
            a ^= b;
            b = car << 1;
        }
        return a;
    }
};