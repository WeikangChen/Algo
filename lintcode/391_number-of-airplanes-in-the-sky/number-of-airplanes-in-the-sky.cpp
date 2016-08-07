/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/number-of-airplanes-in-the-sky
@Language: C++
@Datetime: 16-05-11 03:00
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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, bool> > va;
        for (auto &i : airplanes) {
            va.push_back(make_pair(i.start, true));
            va.push_back(make_pair(i.end, false));
        }
        sort(va.begin(), va.end());
        int max_cnt =0, cnt = 0;
        for (auto &a : va) {
            if (a.second)
                cnt++;
            else
                cnt--;
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};