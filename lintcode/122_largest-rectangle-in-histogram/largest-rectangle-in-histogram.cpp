/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/largest-rectangle-in-histogram
@Language: C++
@Datetime: 16-07-22 00:04
*/

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        height.push_back(0);
        const int n = height.size();
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < n;) {
            if (stk.empty() || height[stk.top()] < height[i])
                stk.push(i++);
            else {
                int j = stk.top(); stk.pop();
                int k = stk.empty() ? 0 : stk.top() + 1;
                res = max(res, (i-k) * height[j]);
            }
        }
        height.pop_back();
        return res;
    }
};
