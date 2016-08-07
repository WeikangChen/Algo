/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-05-01 18:58
*/

class Solution {
public:
    /** 
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        priority_queue<int> max_que;
        priority_queue<int> min_que;
        for (auto n : nums) {
            if (max_que.size() <= min_que.size()) {
                min_que.push(-n);
                max_que.push(-min_que.top());
                min_que.pop();
            } else {
                max_que.push(n);
                min_que.push(-max_que.top());
                max_que.pop();
            }
        }
        return max_que.top();
    }
};
