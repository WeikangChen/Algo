class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        if not s:
            return []
        res = []
        one = []
        self.recur(0, len(s), s, one, res)
        return res

    def recur(self, p, n, s, one, res):
        if p == n:
            res.append(one[:])
            return

        for i in range(p, n):
            cur = s[p:i+1]
            print cur,
            if self.pal(cur):
                one.append(cur)
                self.recur(i+1, n, s, one, res)
                one.pop()
            print "EOF"

    def pal(self, cur):
        i, j = 0, len(cur)-1
        while i < j:
            if cur[i] != cur[j]:
                return False
            i, j = i+1, j-1
        return True
