/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 16-04-21 14:07
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int cnt = 0;
        while (num) {
            num &= (num-1);
            cnt++;
        }
        return cnt;
    }
};