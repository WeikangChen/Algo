#include <iostream>
#include "inline_conxtexpr.hpp"

using namespace std;

void b() {
    cout << static_int << "@"<< &static_int << endl;
    cout << constexpr_int << "@" << &constexpr_int << endl;
    cout << inline_int << "@" << &inline_int << endl;
    cout << "B():Done" << endl;
}
