/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-07-01 19:55
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        const int m = A.size();
        const int n = B.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        int res = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        return res;
    }
};
