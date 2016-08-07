/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-07-01 15:29
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (!source || !target) return -1;
        const int n = strlen(source);
        const int m = strlen(target);
        if (!m) return 0;
        
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && source[i+j] == target[j]) j++;
            if (j == m) return i;
        }
        return -1;
    }
};
