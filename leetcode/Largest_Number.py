




class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        num = sorted(num, cmp=self.bigger)
        res = ""
        for a in num: res = res + str(a)
        if res[0] is '0': return '0'
        return res

    def bigger(self, a, b):
        s1 = str(a) + str(b)
        s2 = str(b) + str(a)
        if s1<s2: return 1
        if s1>s2: return -1
        return 0


def main():
    num = [8, 123, 321, 92, 993, 9, 9]
    s = Solution()
    print s.largestNumber(num)

if __name__ == '__main__':
    main()
