/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: C++
@Datetime: 16-05-27 01:04
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {}

    void push(int element) {
        stack1.push(element);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};
