
class SuffixTrie:
    def __init__(self, t):
        t += '$'
        self.root = {}
        for i in xrange(len(t)):
            cur = self.root
            for c in t[i:]:
                if c not in cur:
                    cur[c] ={}
                cur = cur[c]

    def followPath(self, s):
        cur = self.root
        for c in s:
            if c not in cur:
                return None
            cur = cur[c]
        return cur

    def hasSubstring(self, s):
        return self.followPath(s) is not None

    def hasSuffix(self, s):
        node = self.followPath(s)
        return node is not None and '$' in node




def main():
    strie = SuffixTrie('there would have been a time for such a word')
    strie.hasSubstring('nope')
    strie.hasSubstring('would have been')


if __name__ == "__main__":
    main()
