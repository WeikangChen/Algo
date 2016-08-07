# coding:utf-8
'''
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/binary-representation
@Language: Python
@Datetime: 16-07-09 14:04
'''

class Solution:
    #@param n: Given a decimal number that is passed in as a string
    #@return: A string
    def binaryRepresentation(self, n):
        def parseIntegral(i):
            if not i or i == "0":
                return "0"
            t = int(i)
            integral = ""
            while t:
                integral = str(t % 2) + integral
                t >>= 1
            return integral
            
        def parseFraction(f):
            frac = float("0." + f)
            fraction = ""
            while frac:
                if len(fraction) > 32:
                    return 'ERROR'
                r = frac * 2
                if r >= 1:
                    frac = r - 1
                    fraction += '1'
                else:
                    frac = r
                    fraction += '0'
            return fraction
            
        if '.' not in n:
            return parseIntegral(n)
        else:
            i, f = n.split('.')
            integral = parseIntegral(i) 
            fraction = parseFraction(f)
            if not fraction:
                return integral
            if fraction == "ERROR":
                return "ERROR"
            return integral + '.' + fraction