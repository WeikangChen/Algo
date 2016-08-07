/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: C++
@Datetime: 16-05-14 19:32
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int max_profit = 0;
        int lowest = prices[0];
        for (int &p : prices) {
            lowest = min(lowest, p);
            max_profit = max(max_profit, p - lowest);
        }
        return max_profit;
    }
};
