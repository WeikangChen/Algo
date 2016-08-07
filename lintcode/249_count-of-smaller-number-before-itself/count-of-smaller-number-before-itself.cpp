/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number-before-itself
@Language: C++
@Datetime: 16-06-25 18:29
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        const int n = A.size();
        vector<int> ls;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(ls.begin(), ls.end(), A[i]);
            res[i] = distance(ls.begin(), it);
            ls.insert(it, A[i]);
        }
        return res;
    }
};