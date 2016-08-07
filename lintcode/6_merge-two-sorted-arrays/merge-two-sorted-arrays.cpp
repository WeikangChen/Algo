/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 16-05-01 19:08
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> res;
        const int m = A.size();
        const int n = B.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i] < B[j]) 
                res.push_back(A[i++]);
            else
                res.push_back(B[j++]);
        }
        while(i < m) res.push_back(A[i++]);
        while(j < n) res.push_back(B[j++]);
        return res;
        
    }
};