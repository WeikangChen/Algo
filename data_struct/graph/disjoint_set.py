#!/usr/bin/env python

class Node:
    def __init__(self, x):
        self.value = x
        self.parent = self
        self.rank = 0
    def __str__(self):
        return str(self.value)

def Find(x):
    if x.parent == x:
        return x
    else:
        x.parent = Find(x.parent)
        return x.parent

def Union(x, y):
    if Find(x) != Find(y):
        Merge(Find(x), Find(y))

def Merge(x, y):
    if x.rank < y.rank:
        x.parent = y
    else:
        y.parent = x
        if x.rank == y.rank:
            x.rank = x.rank + 1

if __name__ == "__main__":
    T = input()
    L = [Node(x) for x in range(T)]
    M = []

    for i in xrange(T):
        line = raw_input().strip()
        cs = [c for c in line]
        M.append(cs)
    for i in xrange(T):
        for j in xrange(i):
            if M[i][j] == 'Y':
                Union(L[i], L[j])

    sets = set([str(Find(x)) for x in L])
    #print "sets = ", sets
    print len(sets)
