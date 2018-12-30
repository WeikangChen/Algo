#include <iostream>
#include <memory>
#include <string>
using namespace std;


class X {
    static int cnt;
    int id;
public:
    X() {
        id = cnt++;
        cout << "ctor() " << id << endl;
    }
    ~X() {
        cout << "dstr() " << id << endl;
    }
};

int X::cnt = 0;

int main() {
    auto ua = make_unique<X>();
//    auto ub = make_unique<X>();
//    ua.reset(new X());
    auto ub = ua.release();
    cout << "end" << endl;
}
