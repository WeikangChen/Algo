/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 16-07-07 13:28
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        return binomial(n+m-2, n-1);
    }

    int binomial(int n, int k) {
        long long res = 1;
        k = min(k, n-k);
        for (int i = 0; i < k; ++i) {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
};
