#include <iostream>
#include <vector>

using namespace std;

    
int eval(string expr) {
    const char *p = expr.c_str();
    int num = 0;
    int sig = 1;
    stack<int> stk;
    
    while(*p) {
        char c = *p;
        if(isdigit(c)) {
            num = 10*num + c - '0';
        }
        else if(c == '*') {
            
        }
        else 
    }
}

void dfs(string num, int p, int tar, vector<string> &res) {
    if(p == num.size()) {
        if(eval(num) == tar) res.push_back(num);
        return;
    }
    for(int i = p+1; i < num.size(); ++i)
    {
        string pre = num.substr(0, i);
        string aft = num.substr(i);
        dfs(num, p+1, tar, res);
        dfs(pre+"+"+aft, i, tar, res);
        dfs(pre+"-"+aft, i, tar, res);
        dfs(pre+"*"+aft, i, tar, res);
    }
}


vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(num, 0, target, res);
    return res;
}
    
int main(int argc, char ** argv)
{
    vector<string> res = addOperators("123", 0);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
