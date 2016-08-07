/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 16-07-05 18:04
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        return {lower(A, target), upper(A, target)};
    }
    
    int lower(vector<int> &A, int target) {
        if (A.empty()) return -1;
        int l = 0;
        int r = A.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return l < A.size() && A[l] == target ? l : -1;
    }
    
    int upper(vector<int> &A, int target) {
        if (A.empty()) return -1;
        int l = 0;
        int r = A.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        if (l == 0) return A[l] == target ? 0 : -1;
        return A[l-1] == target ? l-1 : -1;
    }
};