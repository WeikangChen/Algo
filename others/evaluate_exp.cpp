#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int evaluateExpression(vector<string> &expression) {
    int num = 0;
    int sum_opt = 1;
    int sum = 0;
    int prod_opt = 1;
    int prod = 1;
    const int tot = expression.size();
    for (int i = 0; i < tot; ++i) {
        string exp = expression[i];
        if (exp == "+" || exp == "-") {
            if (prod_opt)
                sum += sum_opt * prod * num;
            else
                sum += sum_opt * prod / num;
            sum_opt = (exp == "+" ? 1 : -1);
            prod_opt = 1;
            prod = 1;
            num = 0;
        } else if (exp == "*" || exp == "/") {
            if (prod_opt)
                prod *= num;
            else
                prod /= num;
            prod_opt = (exp == "*" ? 1 : 0);
            num = 0;
        } else if (exp == "(") {
            vector<string> subexp;
            i++;
            while (i < tot && expression[i] != ")") {
                cout << "add " << expression[i] << endl;
                subexp.push_back(expression[i++]);
            }
            num = evaluateExpression(subexp);
            cout << "Enter into level got " << num << endl;
        } else {
            for (auto &c : exp)
                num = 10 * num + c - '0';
        }
        cout << exp << ", sum,prod = "<< sum  << "," << prod << ", num = " << num << endl;
    }
    if (prod_opt)
        sum += sum_opt * prod * num;
    else
        sum += sum_opt * prod / num;
    return sum;
}

int main(int argc, char *argv[])
{
    vector<string> exp = {"(", "(", ")" ")"};

    cout << evaluateExpression(exp) << endl;
    return 0;
}
