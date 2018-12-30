#include <iostream>
#include <vector>
#include <cstdint>
#include <limits> 
#include "rank.hpp"

using namespace std;
/*
weikang test $ g++ -std=c++11 rank.cpp
weikang test $ a.out
0
1
2
3
i
i
d
d
*/

/*
template<class T>
struct my_rank { static const size_t value = 0u; };

template<class U, size_t N>
struct my_rank<U[N]> { static const size_t value = 1u + my_rank<U>::value; };
*/

template<bool B, class T, class F>
struct my_conditional { typedef T type; };
 
template<class T, class F>
struct my_conditional<false, T, F> { typedef F type; };

template<bool, class T = void>
struct my_enable_if { typedef T type; };

template<class T>
struct my_enable_if<false, T> {};

// SFINAE: Substitution Failure Is Not An Error;
// Formally known as explicit overload set management.

template<class T>
typename my_enable_if<is_integral<T>::value, int64_t>::type
my_max(T val)
{
    return numeric_limits<T>::max();
}

template<class T>
typename my_enable_if<is_floating_point<T>::value, long double>::type
my_max(T val)
{
    return numeric_limits<T>::max();
}

template<class T, T v>
struct my_integral_constant {
    static constexpr T value = v;
    constexpr   operator T () const noexcept {return value;}
    constexpr T operator() () const noexcept {return value;}
};

template<bool b>
using my_bool_constant = integral_constant<bool, b>;
using my_true_type = my_bool_constant<true>;
using my_false_type = my_bool_constant<false>;

template<class T>
struct my_rank : my_integral_constant<size_t, 0u> {};

template<class U, size_t N>
struct my_rank<U[N]> : my_integral_constant<size_t, 1u + my_rank<U>::value> {};

template<class U>
struct my_rank<U[]> : my_integral_constant<size_t, 1u + my_rank<U>::value> {};

int main(int argc, char ** argv)
{
    cout << my_rank<int>::value << endl;
    cout << my_rank<bool[10]>::value << endl;
    cout << my_rank<uint32_t[1][2]>::value << endl;
    cout << my_rank<double[][1][2]>::value << endl;

    const int q = -10;
    my_conditional<(q < 0), int32_t, uint32_t>::type vq;
    cout << typeid(vq).name() << endl;

    typedef conditional<true, int, double>::type Type1;
    typedef conditional<false, int, double>::type Type2;
    typedef conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
    cout << typeid(Type1).name() << endl;
    cout << typeid(Type2).name() << endl;
    cout << typeid(Type3).name() << endl;

    int64_t t1 = 42;
    float t2 = 3.14;
    cout << my_max(33) << endl;
    cout << my_max(3.14) << endl;
    cout << my_max(t1) << endl;
    cout << my_max(t2) << endl;


    return 0;
}
