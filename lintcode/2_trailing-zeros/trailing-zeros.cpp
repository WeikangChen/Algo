/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 16-04-24 21:32
*/

class Solution {
  public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long cnt = 0;
        while (n) {
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
