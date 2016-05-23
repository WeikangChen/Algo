#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > visit(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dfs(matrix, visit, i, j, m, n, res);

        return res;
    }

    int dfs (vector<vector<int> >& M, vector<vector<int> >& V, int i, int j, int m, int n, int &res)
    {
        if(V[i][j]) return V[i][j];

        int cur = 0;
        if(i > 0 && M[i][j] < M[i-1][j])
            cur = max(cur, dfs(M, V, i-1, j, m, n, res));
        if(i < m-1 && M[i][j] < M[i+1][j])
            cur = max(cur, dfs(M, V, i+1, j, m, n, res));
        if(j > 0 && M[i][j] < M[i][j-1])
            cur = max(cur, dfs(M, V, i, j-1, m, n, res));
        if(j < n-1 && M[i][j] < M[i][j+1])
            cur = max(cur, dfs(M, V, i, j+1, m, n, res));

        V[i][j] = cur + 1;
        res = max(res, V[i][j]);
        return V[i][j];
    }
};

int main(int argc, char ** argv)
{
    const int m = 3;
    const int n = 3;
    vector<vector<int> > matrix(m, vector<int>(n));
    int va[] = {9,9,4,6,6,8,2,1,1};
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = va[3*i + j];

    vector<vector<int> >::iterator it;
    vector<int>::iterator is;
    for(it = matrix.begin(); it != matrix.end(); it++) {
        for(is = (*it).begin(); is != (*it).end(); is++) {
            cout << *is << "  " ;
        }
        cout << endl ;
    }
    cout << endl;

    Solution sol;
    cout << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
