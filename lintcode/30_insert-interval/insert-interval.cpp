/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-04-24 03:30
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        const int n = intervals.size();
        int i = 0;
        for (; i < n; ++i) {
            Interval cur = intervals[i];
            if (newInterval.end < cur.start) {
                break;
            } else if (newInterval.start <= cur.end) {
                newInterval.start = min(newInterval.start, cur.start);
                newInterval.end = max(newInterval.end, cur.end);
            } else {
                res.push_back(cur);
            }
        }
        res.push_back(newInterval);
        while(i < n) res.push_back(intervals[i++]);
        return res;
    }
};