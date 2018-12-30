#pragma once

#include<iostream>

#define SHOWME(T) { std::cout << __func__  <<  "<" << #T << ">" << std::endl; }

// #define SHOWME(T) { std::cout << __PRETTY_FUNCTION__ << #T << std::endl; }

template<typename T>
using IsNotReference = std::enable_if_t<!std::is_reference<T>::value>;
 
template<typename T>
class MyClass
{
public:
    void f(T const& x){
        SHOWME(T);
    }
    
    template<typename T_ = T, typename = IsNotReference<T_>>
    void f(T&& x){
        SHOWME(T);
    }
};

class pricer_a {};
class pricer_b {};

template<typename T>
class pricer1
{
public:
    // template<typename T_ = T, typename = std::enable_if_t<!std::is_same<T_, pricer_a>::value>>
    void reset_b_rate(double box_rate, double roll_rate);
    
    // template<typename T_ = T, typename = std::enable_if_t<std::is_same<T_, pricer_a>::value>>
    void reset_a_rate(double box_rate);
};

template<>
void pricer1<pricer_a>::reset_a_rate(double box_rate)
{
    SHOWME(pricer_a);
}

template<typename T>
void pricer1<T>::reset_b_rate(double box_rate, double roll_rate)
{
    SHOWME(T);
}


template<typename T>
class pricer2
{
public:
    template<typename T_ = T, typename = std::enable_if_t<!std::is_same<T_, pricer_a>::value>>
    void reset_b_rate(double box_rate, double roll_rate)
    {
        SHOWME(T);
        std::cout << box_rate << "," << roll_rate << std::endl;
    }
    
    template<typename T_ = T, typename = std::enable_if_t<std::is_same<T_, pricer_a>::value>>
    void reset_a_rate(double box_rate)
    {
        SHOWME(T);
        std::cout << box_rate << std::endl;
    }
};

/*
template<>
template<>
void pricer2<pricer_a>::reset_a_rate(double box_rate)
{
    SHOWME;
}


template<typename T>
template<>
void pricer2<T>::reset_b_rate()
{
    SHOWME;
}
*/
