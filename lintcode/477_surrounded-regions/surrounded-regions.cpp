/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/surrounded-regions
@Language: C++
@Datetime: 16-07-21 03:28
*/

class Solution {
private:
    int m;
    int n;
public:
    void surroundedRegions(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; ++i)
            dfsUtil(i, 0, board);
        
        for (int j = 1; j < n; ++j)
            dfsUtil(0, j, board);
            
        if (n > 1)
            for (int i = 1; i < m; ++i)
                dfsUtil(i, n-1, board);
        
        if (m > 1)
            for (int j = 1; j < n; ++j)
                dfsUtil(m-1, j, board);
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'C')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
    }
    
    void dfsUtil(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (board[i][j] == 'X' || board[i][j] == 'C') return;
        board[i][j] = 'C';
        
        dfsUtil(i-1, j, board);
        dfsUtil(i+1, j, board);
        dfsUtil(i, j-1, board);
        dfsUtil(i, j+1, board);
    }
};