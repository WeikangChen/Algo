/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-07-24 14:23
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0.0;
        if (n < 0) return myPow(1.0/x, -n);
        return util(x, n);
    }
    
    double util(double x, int n) {
        if (n == 1) return x;
        double tmp = util(x, n/2);
        if (n & 1) 
            return x * tmp * tmp;
        else
            return tmp * tmp;
    }
};