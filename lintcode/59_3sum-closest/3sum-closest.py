# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: Python
@Datetime: 16-07-02 22:49
'''

class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target : An integer
    @return : return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
        numbers.sort()
        n = len(numbers)
        min_diff = numbers[0] + numbers[1] + numbers[2] - target

        for i in range(n-2):
            cur = numbers[i]
            j, k = i + 1, n-1
            while j < k:
                sum = cur + numbers[j] + numbers[k]
                if abs(sum-target) < abs(min_diff):
                    min_diff = sum - target
                if sum < target:
                    j += 1
                elif sum > target:
                    k -= 1
                else: 
                    return target
        return target + min_diff
        