#include <iostream>
#include <utility>
#define SHOWME { std::cout << __PRETTY_FUNCTION__ << std::endl; }

/*
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& con)
{
    SHOWME;
    os << "[";
    auto it = con.begin();
    while(true) {
        os << *it;
        if (++it == con.end())
            break;
        os << ", ";
    }
    os << ']' << std::endl;
    return os;
}
*/

template <typename T, typename U>
auto mult(T t, U u) -> decltype(t * u)
{
    return t * u;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

template<template<typename, typename...> class ContainerType,
typename ValueType, typename... Args>
void print_container(std::ostream& os,
                     const ContainerType<ValueType, Args...>& con)
{
    //SHOWME;
    os << "[";
    auto it = con.begin();
    while(true) {
        os << *it;
        if (++it == con.end())
            break;
        os << ", ";
    }
    os << ']' << std::endl;
}

template<template<typename, typename...> class ContainerType,
typename ValueType, typename... Args>
std::ostream& operator<<(std::ostream& os,
                         const ContainerType<ValueType, Args...>& con)
{
    //SHOWME;
    os << "[";
    auto it = con.begin();
    while(true) {
        os << *it;
        if (++it == con.end())
            break;
        os << ", ";
    }
    os << ']';
    return os;
}


