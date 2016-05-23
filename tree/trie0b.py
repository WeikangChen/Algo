class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.value = None
        self.children = {}
        

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        node = self.root
        for c in word:
            if c not in node.children:
                child = TrieNode()
                node.children[c] = child
                node = child
            else:
                node = node.children[c]
        node.value = word
        

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.root
        for c in word:
            if c not in node.children:
                return false
            else:
                node = node.children[c]
        return node.value is word

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        for c in prefix:
            if c not in node.children:
                return false
            else:
                node = node.children[c]
        return True


def main():
    print __name__

    tree = Trie()
    tree.insert('ab')
    tree.insert('abcd')
    tree.insert('abasdfasdf')
    tree.insert('acd')
    tree.insert('betters')
    tree.insert('better')
    tree.insert('best')
    a = tree.startsWith('ab')
    c = tree.search('ab')
    d = tree.search('be')
    print a
    print c
    print d

if __name__ == '__main__': 
    main()
