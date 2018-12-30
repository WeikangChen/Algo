#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <cstdio>

/* to compile: g++ -std=c++17 inline*.cpp, points to remember:
 * functions or variables definition in hpp included in multiple cpp must be either of following two cases:
 *  1. internal linkage: static
 *  2. external linkage: with one-definetion rule (ODR) relaxed (by inline)
 * https://stackoverflow.com/questions/22102919/static-vs-inline-for-functions-implemented-in-header-files
 */
static int static_int = 1000;
static int static_sum(int a, int b) 
{
    static int base = 10;
    return a + b + static_int + base++;
}

// https://stackoverflow.com/questions/45987571/difference-between-constexpr-and-static-constexpr-global-variable
// constexpr implies const. const implies static
// constexpr on variables implies const, and const integral at namespace scop implies static (internal linkage)
constexpr int constexpr_int = 2000;
// constexpr function implies inline <= https://en.cppreference.com/w/cpp/language/inline
constexpr int constexpr_sum(int a, int b) 
{
    constexpr int base = 20;
    return a + b + constexpr_int + base;
}

// inline function or variable (since c++17) with external linkage could be more than one definition and:
// 1. It must be declared inline in every translation unit.
// 2. It has the same address in every translation unit.
static inline int inline_int = 3000;
// same as: inline constexpr int inline_int = 2000;
// reason: inline const variables at namespace scope have external linkage by default
static inline int inline_sum(int a, int b) 
{
    static int base = 30;
    return a + b + inline_int + base++;
}


#endif
