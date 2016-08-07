# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/3sum
@Language: Python
@Datetime: 16-07-02 22:30
'''

class Solution:
    """
    @param numbersbers : Give an array numbersbers of n integer
    @return : Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        numbers.sort()
        n = len(numbers)
        res = []
        i = 0
        while i < n-2:
            cur = numbers[i]
            j, k = i + 1, n-1
            while j < k:
                sum = cur + numbers[j] + numbers[k]
                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    res.append([cur, numbers[j], numbers[k]])
                    j, k = j + 1, k - 1
                    while (j < k and numbers[j] == numbers[j-1]): 
                        j += 1
                    while (j < k and numbers[k] == numbers[k+1]): 
                        k -= 1
            i += 1
            while i < n-2 and numbers[i] == numbers[i-1]:
                i += 1
        return res
        