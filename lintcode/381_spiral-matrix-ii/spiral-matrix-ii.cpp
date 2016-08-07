/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 16-07-22 20:53
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n <=0) return res;
        res.resize(n, vector<int>(n, 0));
        int cnt = 1;
        int nsq = n*n;
        int n1 = 0, n2 = n-1;
        
        while(n1 < n2) 
        {
            for(int i = n1, j = n1; j < n2; ++j) res[i][j] = cnt++;
            for(int j = n2, i = n1; i < n2; ++i) res[i][j] = cnt++;
            for(int i = n2, j = n2; j > n1; --j) res[i][j] = cnt++;
            for(int j = n1, i = n2; i > n1; --i) res[i][j] = cnt++;
            n1++; n2--;
        }
        if(n1==n2) res[n1][n2] = cnt;
        return res;
    }
};