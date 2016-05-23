#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    int pairs;
public:
    vector<string> removeInvalidParentheses(string s) {

        const int n = s.size();
        int l = 0;
        int r = n - 1;
        while( l < n && s[l] == ')') l++;
        while( r >= l && s[r] == '(') r--;

        unordered_set<string> res;
        string cur;     
        s = s.substr(l, r - l + 1);
        int leftp = 0;
        pairs = 0;
        for(auto c: s)
        {
            if(c == '(') leftp++;
            else if(c == ')' && pairs < leftp) pairs++;
        }
        dfs(s, 0, 0, 0, cur, res);

        return vector<string>(res.begin(), res.end());
    }
    
    void dfs(string &s, int p, int l, int r, string &cur, unordered_set<string> &res)
    {
        if(l < r) return;
        if(l > pairs) return;
        if(p == s.size()){
            if(l == r && r == pairs) 
                res.insert(cur);
            return;
        }
        
        char c = s[p++];
        cur.push_back(c);
        if( c != '(' && c != ')')
            dfs(s, p, l, r, cur, res);
        else if(c == '(')
            dfs(s, p, l+1, r, cur, res);
        else if(c == ')')
            dfs(s, p, l, r+1, cur, res);
        cur.pop_back();

        if(c == '(' || c == ')')
            dfs(s, p, l, r, cur, res);
    }
};

int main(int argc, char ** argv)
{
    Solution sol;
    string str("((s(())()(()))((((((");
    vector<string> res = sol.removeInvalidParentheses(str);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
