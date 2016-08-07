/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 16-05-22 21:30
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int occurence = 0;
        int i = 0, j = n - 1;

        while (i < m && j >= 0) {
            if (matrix[i][j] < target ) {
                i++;
            } else if ( matrix[i][j] > target) {
                j--;
            } else {
                occurence++;
                i++;
            }
        }
        return occurence;
    }
};
