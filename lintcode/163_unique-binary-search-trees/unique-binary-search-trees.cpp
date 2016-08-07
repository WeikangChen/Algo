/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: C++
@Datetime: 16-07-07 14:37
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> cat(n + 1, 0);
        cat[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                cat[i] += cat[j] * cat[i-1-j];
        return cat[n];
    }
};