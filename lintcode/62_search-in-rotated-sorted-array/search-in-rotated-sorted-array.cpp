/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array
@Language: C++
@Datetime: 16-07-05 18:29
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if (A.empty()) return -1;
        int l = 0;
        int r = A.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] == target) return m;
            if (A[l] < A[m]) {
                if (A[l] <= target && target < A[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (A[m] < target && target <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return A[l] == target ? l : -1;
    }
};