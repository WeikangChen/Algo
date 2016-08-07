/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-04-24 18:33
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int A1[m];
        for (int i = 0; i < m; ++i) A1[i] = A[i];
        int i, j, k;
        i = j = k = 0;
        while (i < m && j < n) {
            if (A1[i] < B[j])
                A[k++] = A1[i++];
            else
                A[k++] = B[j++];
        }
        while (i < m) A[k++] = A1[i++];
        while (j < n) A[k++] = B[j++];
    }
};