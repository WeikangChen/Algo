/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-07-24 02:42
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto &one: tokens) {
            if (one == "+" || one == "-" || one == "*" || one == "/") {
                int t1 = stk.top(); stk.pop();
                int t2 = stk.top(); stk.pop();
                switch (one[0]) {
                    case '+': stk.push(t2 + t1); break;
                    case '-': stk.push(t2 - t1); break;
                    case '*': stk.push(t2 * t1); break;
                    case '/': stk.push(t2 / t1); break;
                }
            } else stk.push(stoi(one));
        }
        return stk.top();
    }
};