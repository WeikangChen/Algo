/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 16-05-22 21:50
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if (a == 0 || b < 2) return 0;
        return int(util(a, b, n));
    }
    
    long long util(int a, int b, int n) {
        if (n == 0) return 1;
        long long tmp = util(a, b, n/2);
        tmp = tmp * tmp % b; 
        if (n & 1)
            return tmp * a % b;
        else
            return tmp % b;
    }
};