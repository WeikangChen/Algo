#!/usr/bin/env python
# http://blog.csdn.net/psrincsdn/article/details/8158182
import sys, pickle, re

class Complex:
    def __init__(self, real, image):
        self.r = real
        self.i = image
    def show(self):
        print self.r, self.i

class TrieNode(object):
    def __init__(self):
        self.value = None
        self.children = {}

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
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
        node = self.root
        for c in word:
            if c not in node.children:
                return False, None
            else:
                node = node.children[c]
        return True, node.value

    def __collect(self, node):
        results = []
        if node.value:
            results.append(node.value)
        for v in node.children.values():
            results.extend(self.__collect(v))
        return results

    def auto_complete(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                return []
            else:
                node = node.children[c]
        return self.__collect(node)
                

if __name__ == '__main__':
    main()

def main():

    tree = Trie()
    tree.insert('ab')
    tree.insert('abcd')
    tree.insert('abasdfasdf')
    tree.insert('acd')
    tree.insert('betters')
    tree.insert('better')
    tree.insert('best')
    c = tree.auto_complete('abcd')
    d = tree.auto_complete('be')
    print "Begin with abcd"
    print c
    print "----- --------"
    print d
