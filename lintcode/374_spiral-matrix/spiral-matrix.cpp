/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 16-07-22 20:51
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int i = 0, j = 0;
        while(i < m-i && j < n-j)
        {
            for(int j1 = j; j1 < n-j; ++j1)
                res.push_back(matrix[i][j1]);
            for(int i1 = i+1; i1 < m-i; ++i1)
                res.push_back(matrix[i1][n-1-j]);
            if(i == m-1-i) break;
            for(int j1 = n-2-j; j1 >= i; --j1)
                res.push_back(matrix[m-1-i][j1]);
            if(j == n-1-j) break;
            for(int i1 = m-2-i; i1 > i; --i1)
                res.push_back(matrix[i1][j]);
            ++i; ++j;
        }
        return res;
    }
};