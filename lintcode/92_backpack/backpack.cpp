/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 16-07-19 00:24
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {

        vector<bool> dp(m+1, false);
        dp[0] = true;
        
        for (int a: A) 
            for (int i = m; i >= a; --i) 
                    dp[i] = dp[i] || dp[i-a];
                    
        for (int i = m; i >= 0; --i) {
            if (dp[i]) return i;
        }
        return -1;
    }
};