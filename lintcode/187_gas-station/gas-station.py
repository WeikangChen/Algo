# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: Python
@Datetime: 16-07-09 14:19
'''

class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        min_gas = gas[0] - cost[0]
        min_pos = 0
        tot_gas = min_gas
        for i in range(1, n):
            cur_gas = gas[i] - cost[i]
            tot_gas += cur_gas
            if tot_gas < min_gas:
                min_gas = tot_gas
                min_pos = i
        return (min_pos + 1) % n if tot_gas >= 0 else -1