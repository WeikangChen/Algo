#include <iostream>
#include <vector>
#include "inline_a.hpp"
#include "inline_b.hpp"
using namespace std;

int main(int argc, char ** argv)
{
    cout << a() << endl;
    cout << a() << endl;
    cout << b() << endl;
    cout << b() << endl;
    return 0;
}
