/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 16-07-11 23:17
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        const int n = A.size();
        string res = "";
        int i = 0;
        while (res.size() < n-k) {
            int min_pos = i;
            char min_val = A[i];
            for (int j = i + 1; j < k + 1 + res.size(); ++j) {
                if (A[j] < min_val) {
                    min_val = A[j];
                    min_pos = j;
                }
            }
            res += min_val;
            i = min_pos + 1;
        }
        while (res.size() && res[0] == '0') res.erase(0, 1);
        return res;
    }
};
