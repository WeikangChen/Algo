/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 16-07-15 01:12
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        if (S.empty()) return 0;
        if (T.empty()) return 1;
        const int m = S.size();
        const int n = T.size();
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j > 0; --j) {
                if (S[i-1] == T[j-1])
                    dp[j] += dp[j-1];
                    
            }
        }
        return dp[n];
    }
};
