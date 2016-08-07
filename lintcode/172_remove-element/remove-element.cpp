/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-04-25 15:34
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        const int n = A.size();
        int j = 0;   
        for (int i = 0; i < n; ++i) {
            if(A[i] != elem) swap(A[j++], A[i]);
        }
        return j;
    }
};