/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/data-stream-median
@Language: C++
@Datetime: 16-07-21 23:53
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int> max_heap;
        priority_queue<int> min_heap;
        vector<int> res;
        for (auto n: nums) {
            if (max_heap.size() <= min_heap.size()) {
                min_heap.push(-n);
                max_heap.push(-min_heap.top());
                min_heap.pop();
            } else {
                max_heap.push(n);
                min_heap.push(-max_heap.top());
                max_heap.pop();
            }
            res.push_back(max_heap.top());
        }
        return res;
    }
};
