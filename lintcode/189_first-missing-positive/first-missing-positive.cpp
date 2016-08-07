/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 16-07-05 15:17
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        if (A.empty()) return 1;
        const int n = A.size();
        for (int i = 0; i < n; ++i) 
            while (A[i] != i + 1 && A[i] > 0 && A[i] <= n) {
                int j = A[i] - 1;
                if (A[j] == j + 1) break;
                swap(A[i], A[j]);
            }
        for (int i = 0; i < n; ++i)
            if (A[i] != i + 1) return i + 1;
        return n+1;
    }
};