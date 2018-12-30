#include <iostream>
#include <vector>
#include <map>
#include "enable_if.hpp"

// using namespace std;

int main(int argc, char ** argv)
{
    int x;
    MyClass<int> a;
    a.f(1);
    a.f(x);

    pricer1<pricer_a> pa;
    pa.reset_a_rate(1.0);
    pa.reset_b_rate(1.0, 2.0);

    pricer1<pricer_b> pb;
    // pb.reset_a_rate();
    pb.reset_b_rate(2.0, 3.0);

    pricer2<pricer_a> pqa;
    pqa.reset_a_rate(1.0);
    // pqa.reset_b_rate(1.0, 2.0);

    pricer2<pricer_b> pqb;
    // pqb.reset_a_rate();
    pqb.reset_b_rate(2.0, 3.0);

    pricer1
}
