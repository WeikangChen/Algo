/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/interval-sum
@Language: C++
@Datetime: 16-06-25 14:47
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        const int n = A.size();
        vector<long long> acc(n+1, 0);
        vector<long long> res(queries.size());
        for (int i = 1; i <= n; ++i)
            acc[i] = acc[i-1] + A[i-1];

        for (int i = 0; i < queries.size(); ++i) {
            Interval q = queries[i];
            res[i] = acc[q.end+1] - acc[q.start];
        }
        return res;
    }
};