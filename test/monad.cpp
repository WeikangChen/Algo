#include <iostream>
#include <vector>
#include "monad.h"

using namespace std;

class Foo
{
    int val_;
public:
    explicit Foo(int v) : val_(v) {}
    int get_val() { return val_; }
};

void show_foo(Foo f)
{
    cout << f.get_val() << endl;
}

int main(int argc, char ** argv)
{
    auto maybe_i = Just<int>(10);
    auto maybe_j = Nothing<int>();
    maybe_i.show();
    maybe_j.show();

    auto inc = [](int v) {
        // cout << "lambda inc is calling on " << v << endl;
        return Maybe<int>(v+1);
    };

    function<Maybe<int>(int)> inc1 = [](int v) {
        // cout << "lambda inc is calling on " << v << endl;
        return Maybe<int>(v+1);
    };
    
    for (int i  = 0; i < 3; ++i) {
        maybe_i = and_then(maybe_i, inc1);
        maybe_i.show();
    }

    show_foo(Foo{99});
    // show_foo(99);
    return 0;
}
