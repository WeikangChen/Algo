/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-07-21 23:59
*/

class MinStack {
    stack<int> stk;
    stack<int> stk_min;
public:
    MinStack() {}

    void push(int number) {
        stk.push(number);
        if (stk_min.empty() || number <= stk_min.top())
            stk_min.push(number);
        else
            stk_min.push(stk_min.top());
    }

    int pop() {
        int top = stk.top();
        stk.pop();
        stk_min.pop();
        return top;
    }

    int min() {
        return stk_min.top();
    }
};
