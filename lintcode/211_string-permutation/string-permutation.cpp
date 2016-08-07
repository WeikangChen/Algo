/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/string-permutation
@Language: C++
@Datetime: 16-07-22 19:14
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        int hs[256] = {0};
        const int n = A.size();
        if (B.size() != n) return false;
        for (int i = 0; i < n; ++i) {
            hs[A[i]]++;
            hs[B[i]]--;
        }
        for (int i = 0; i < 256; ++i)
            if (hs[i]) return false;
        return true;
    }
};