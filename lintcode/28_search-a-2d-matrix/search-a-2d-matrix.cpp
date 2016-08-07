/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-07-05 15:32
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        const int M = matrix.size();
        const int N = matrix[0].size();
        int l = 0, r = M * N -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cur = matrix[mid/N][mid%N];
            if (cur < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[l/N][l%N] == target;
    }
};
