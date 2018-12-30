#include <vector>
#include <iostream>
using namespace std;


class stk {
    int n;
public:
    stk(int x = 0): n{x} {
        cout << __func__ << ": "<< n << endl;
    }
    void show () {
        cout << __func__ << ": "<< n << endl;
    }
};

void fun(stk stks) {
    stk fs = std::move(stks);
    fs.show();
}

constexpr unsigned fibonacci(const unsigned x) {
  return x <= 1 ? 
    1 : 
    fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
    stk stks{10};
    fun(move(stks));
    return fibonacci(10);
}
