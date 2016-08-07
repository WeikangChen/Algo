/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-search
@Language: C++
@Datetime: 16-07-24 23:25
*/

class Solution {
    int m;
    int n;
    string m_word;
    vector<vector<bool>> onpath;
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        m = board.size();
        n = board[0].size();
        m_word = word;
        onpath.clear();
        onpath.resize(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if(util(board, i, j, 0))
                    return true;
        return false;
    }
    
    bool util(vector<vector<char> > &board, int i, int j, int p) {
        
        
        if(onpath[i][j]) return false;
        if (m_word[p] != board[i][j]) return false;
        if (++p == m_word.size()) return true;
        
        onpath[i][j] = true;
        if (i > 0 && util(board, i-1, j, p)) return true;
        if (i < m-1 && util(board, i+1, j, p)) return true;
        if (j > 0 && util(board, i, j-1, p)) return true;
        if (j < n-1 && util(board, i, j+1, p)) return true;
        return onpath[i][j] = false;
    }
};