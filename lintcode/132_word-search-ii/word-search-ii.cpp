/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/word-search-ii
@Language: C++
@Datetime: 16-07-21 01:30
*/


class Trie {
    struct Node{
        string word;
        unordered_map<char, Node*> children;
        Node* parent;
        bool end;
        Node(Node *p=NULL): word(""), children(), parent(p), end(false) {}
    };
    Node *root;
    Node *cur;
public:
    Trie(): root(new Node()) {
        cur = root;
    }
    
    void addWord(string word) {
        Node *cur = root;
        for (auto c: word) {
            auto it = cur->children.find(c); 
            if (it == cur->children.end())
                cur->children[c] = new Node(cur);
            cur = cur->children[c];
        }
        cur->word = word;
        cur->end = true;
    }
    

    bool next(char c) {
        auto it = cur->children.find(c);
        if (it == cur->children.end())
            return false;
        else 
            cur = it->second;

        return true;
    }
    void prev() {
        if (cur->parent)
            cur = cur->parent;
    }
    bool findWord() {
        return cur->end;
    }
    string curWord() {
        return cur->word;
    }
};

class Solution {
private:
    int m;
    int n;
    
public:
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        if (board.empty() || board[0].empty()) return {};
        m = board.size();
        n = board[0].size();
        
        Trie trie;    
        for (auto &w: words) 
            trie.addWord(w);
        
        set<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool>> onpath(m, vector<bool>(n, false));
                dfsUtil(board, i, j, trie, res, onpath);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
        
    void dfsUtil(vector<vector<char> > &board, int i, int j, Trie &trie, set<string> &res, vector<vector<bool>> &onpath) {

        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (onpath[i][j]) return;
        onpath[i][j] = true;

        if (!trie.next(board[i][j])) {
            onpath[i][j] = false; 
            return;
        }
        if (trie.findWord()) res.insert(trie.curWord());
       
        dfsUtil(board, i, j-1, trie, res, onpath);
        dfsUtil(board, i-1, j, trie, res, onpath);
        dfsUtil(board, i+1, j, trie, res, onpath);
        dfsUtil(board, i, j+1, trie, res, onpath);

        trie.prev();
        onpath[i][j] = false;
    }
};