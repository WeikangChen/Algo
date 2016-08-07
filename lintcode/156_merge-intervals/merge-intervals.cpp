/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-07-24 02:10
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
    static bool less(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return intervals;
        const int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), less);
        Interval one = intervals[0];
        vector<Interval> res;
        for (int i = 1; i < n; ++i) {
            Interval cur = intervals[i];
            if (one.end < cur.start) {
                res.push_back(one);
                one = cur;
            } else {
                one.start = min(one.start, cur.end);
                one.end = max(one.end, cur.end);
            }
        }            
        res.push_back(one);
        return res;
    }
};