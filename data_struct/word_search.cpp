#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Trie {
private:
    struct Node{
        string word;
        Node* children[26];
        Node* parent;
        bool end;
        Node(Node *p=NULL): word(""), parent(p), end(false) {
            fill_n(children, 26, nullptr);
        }
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
            int id = c - 'a';
            if (!cur->children[id])
                cur->children[id] = new Node(cur);
            cur = cur->children[id];
        }
        cur->word = word;
        cur->end = true;
    }
    
    bool next(char c) {
        if (!cur->children[c-'a'])
            return false;
        else
            cur = cur->children[c-'a'];
        return true;
    }
    void prev() {
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
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        if (board.empty() || board[0].empty()) return {};
        m = board.size();
        n = board[0].size();
        
        Trie trie;    
        for (auto &w: words) 
            trie.addWord(w);

        vector<vector<bool>> onpath(m, vector<bool>(n, false));        
        set<string> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfsUtil(board, i, j, trie, res, onpath);

        return vector<string>(res.begin(), res.end());
    }
        
    void dfsUtil(vector<vector<char> > &board, int i, int j, Trie &trie, set<string> &res, vector<vector<bool>> &onpath) {
        if (onpath[i][j]) return;
        onpath[i][j] = true;
        if (!trie.next(board[i][j])) {
            onpath[i][j] = false; 
            return;
        }
        if (trie.findWord()) res.insert(trie.curWord());
        
        if (i > 0) dfsUtil(board, i-1, j, trie, res, onpath);
        if (i < m-1) dfsUtil(board, i+1, j, trie, res, onpath);
        if (j > 0) dfsUtil(board, i, j-1, trie, res, onpath);
        if (j < n-1) dfsUtil(board, i, j+1, trie, res, onpath);
        trie.prev();
        onpath[i][j] = false;
    }
};


int main(int argc, char *argv[])
{
    vector<string> vstr = {"ab","de"};
    vector<string> words = {"abed"};
    vector<vector<char>> board;
    const int m = vstr.size();
    const int n = vstr[0].size();
    for (int i = 0; i < m; ++i) {
        vector<char> tmp;
        for (int j = 0; j < n; ++j) {
            tmp.push_back(vstr[i][j]);
        }
        board.push_back(tmp);
    }

    Solution sol;
    vector<string> res = sol.findWords(board, words);
    for (auto str: res) 
        cout << str << endl;
    return 0;
}
