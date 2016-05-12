#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Trie {
private:
    struct TrieNode {
        string val;
        unordered_map<char, TrieNode*> children;
        TrieNode() : val("") {children.clear();}
    };
    
    TrieNode *root;
    
public:

    Trie () {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if(cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode;
            }
            cur = cur->children[c];
        }
        cur->val = word;
    }

    bool search(string word){
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if(cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return cur->val == word;
    }

    bool isStartWith(string word){
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if(cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return true;
    }

    void dfs_complete(TrieNode *cur, vector<string> &res) {
        if(cur->val.size())
            res.push_back(cur->val);
        for(auto a: cur->children)
            dfs_complete(a.second, res);
    }
    
    vector<string> auto_complete(string word) {
        TrieNode *cur = root;
        vector<string> res;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if(cur->children.find(c) == cur->children.end()) return res;
            cur = cur->children[c];
        }

        dfs_complete(cur, res);
        return res;
    }
    

};




int main(int argc, char ** argv)
{
    Trie trie;
    trie.insert("ab");
    trie.insert("abcd");
    trie.insert("abcdasdfad");
    trie.insert("abasdfasdf");
    trie.insert("acd");
    trie.insert("betters");
    trie.insert("better");
    trie.insert("best");
    vector<string> c = trie.auto_complete("abcd");
    vector<string> d = trie.auto_complete("be");

    cout << "abcd ->" << endl;
    for(int i = 0; i < c.size();i++)
        cout << "\t" << c[i] << endl;
    cout << endl;

    cout << "be ->" << endl;
    for(int i = 0; i < d.size();i++)
        cout << "\t" << d[i] << endl;
    cout << endl;
    return 0;
}
