#!/usr/bin/env python  
# http://blog.csdn.net/psrincsdn/article/details/8158182  
import sys, pickle, re 

class TrieNode(object):
    """ A Trie Class """
    def __init__(self):
        self.value = None
        self.children = {}

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, key):
        node = self.root
        for c in key:
            if c not in node.children:
                child = TrieNode()
                node.children[c] = child
                node = child
            else:
                node = node.children[c]
        node.value = key

    def search(self, key):
        node = self.root
        matches = []
        for c in key:
            if c not in node.children:
                break
            node = node.children[c]
            if node.value: 
                matches.append(node.value)
        return matches

    def __collect_values(self, node):
        results = []
        if node.value:
            results.append(node.value)
        for k,v in node.children.iteritems():
            results.extend(self.__collect_values(v))
        return results

    def auto_complete(self, prefix_value):
        node = self.root
        for c in prefix_value:
            if c not in node.children:
                return []
            node = node.children[c]

        return self.__collect_values(node)

def gen_trie(input_file, output_file):
    trie = Trie()
    with open(input_file) as f:
        for line in f:
            line = line.strip()
            trie.add(line)
    with open(output_file, 'wb') as f:
        pickle.dump(trie, f)



if __name__ == '__main__': 
    main()

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
    c = tree.search('ab')
    d = tree.search('be')
    print c
    print d
