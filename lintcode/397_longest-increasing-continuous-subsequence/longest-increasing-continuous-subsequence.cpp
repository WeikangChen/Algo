/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 16-04-24 18:28
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int res = 0;
        const int n = A.size();
        if (!n ) return res;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j+1 < n && A[j+1] > A[j]) j++;
            res = max(res, (j - i + 1));
            i = j;
        }
        for (int i = n-1; i > -1; --i) {
            int j = i;
            while (j > -1 && A[j-1] > A[j]) j--;
            res = max(res, (i - j + 1));
            i = j;
        }
        return res;
    }
};