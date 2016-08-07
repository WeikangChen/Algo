/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 16-07-05 17:27
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 0;
        int r = A.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m-1] < A[m] && A[m] > A[m+1])
                return m;
            else if (A[m-1] < A[m] && A[m] < A[m+1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
