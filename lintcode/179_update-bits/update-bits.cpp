/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: C++
@Datetime: 16-07-08 12:58
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask = (1 << j) - (1 << i) + (1 << j);

        return  (n & (~mask)) | ((m << i) & mask);
    }
};