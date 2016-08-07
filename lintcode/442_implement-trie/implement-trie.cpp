/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/implement-trie
@Language: C++
@Datetime: 16-06-25 15:17
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    int end;
    unordered_map<char, TrieNode*> children;
    TrieNode(): end(0) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            auto it = cur->children.find(c);
            if (it == cur->children.end()) 
                cur = cur->children[c] = new TrieNode();
            else     
                cur = it->second;
        }
        cur->end = 1;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (char c: word) {
            auto it = cur->children.find(c);
            if (it == cur->children.end())
                return false;
            else
                cur = it->second;
        }
        return cur->end == 1;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (char c: prefix) {
            auto it = cur->children.find(c);
            if (it == cur->children.end())
                return false;
            else
                cur = it->second;
        }
        return true;
    }

private:
    TrieNode* root;
};