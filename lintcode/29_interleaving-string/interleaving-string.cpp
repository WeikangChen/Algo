/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 16-05-22 17:52
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.size();
        const int n = s2.size();
        if (m == 0) return s2 == s3;
        if (n == 0) return s1 == s3;
        if (m + n != s3.size()) return false;
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (s1[i-1] == s3[i-1])
                dp[i][0] = true;
            else
                break;
        }

        for (int j = 1; j <= n; ++j) {
            if (s2[j-1] == s3[j-1])
                dp[0][j] = true;
            else
                break;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1])
                        || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[m][n];
    }
};