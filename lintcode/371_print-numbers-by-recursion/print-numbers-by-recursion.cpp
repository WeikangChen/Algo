/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 16-05-27 01:21
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> res;
        recur(0, n, res);
        return res;
    }

    void recur(int p, int n, vector<int> &res) {
        if (p == n) return;
        int i = pow(10, p);
        int end = pow(10, p+1);
        while (i < end) {
            res.push_back(i++);
        }
        recur(p+1, n, res);
    }
};