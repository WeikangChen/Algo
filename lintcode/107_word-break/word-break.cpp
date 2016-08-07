/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 16-07-18 00:43
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();

        int max_len = 0;
        for (auto str: dict) 
            max_len = max(max_len, int(str.size()));
        
        vector<bool> dp(n+1, 0);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= min(n, i+max_len); ++j) {
                if (dp[i] && dict.find(s.substr(i, j-i)) != dict.end()) {
                    dp[j] = true;
                    continue;
                }
            }
        }
        return dp[n];
    }
};