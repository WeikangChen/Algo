
class Solution:

    #1 Two Sum @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        map = {}
        for i in range(len(num)):
            if num[i] in map:
                index1 = map[num[i]]
                index2 = i+1
                break
            map[target-num[i]] = i+1

        return (index1, index2)

    #3 Longest Substring Without Repeating Characters
    def lengthOfLongestSubstring(self, s):
        map = [0] * 256
        res = 0

        p1, p2 = 0, 0
        while p2 < len(s):
            while map[ord(s[p2])] == 1:
                p1 = p1+1
                map[ord(s[p1])] = 0
            map[ord(s[p2])] = 1
            res = max(res, p2-p1+1)
            p2 = p2+1

        return res
    #34 Search for a Range @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        index1 = self.lower(A, target)
        index2 = self.upper(A, target) - 1
        
        if index1 == len(A) or  A[index1] != target:
            return [-1, -1]
        return [index1, index2]
        
    def lower(self, A, target):
        l = 0
        r = len(A)
        while l < r:
            m = l + (r - l) / 2
            if A[m] < target:
                l = m + 1
            else:
                r = m
        return l
        
    def upper(self, A, target):
        l = 0
        r = len(A)
        while l < r:
            m = l + (r - l) / 2
            if A[m] <= target:
                l = m + 1
            else:
                r = m
        return l  

    # @return a string
    def longestPalindrome(self, s):
        n = len(s)
        s, l = 0, 1
        dp = [[0] * n for i in range(n)]
        
        for j in range(n):
            dp[j][j] = 0
            for i in range(j):
                dp[i][j] = (s[i]==s[j]) && (i == j-1 || dp[i+1][j-1])
                if dp[i][j] and j-i+1>l:
                    l = j-i+1
                    s = i
        
        return s[i:i+l]
