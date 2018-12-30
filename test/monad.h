#include <iostream>
#include <sstream>
#include <string>

#define SHOWME { std::cout << __PRETTY_FUNCTION__ << std::endl; }

template<template<typename a, typename...> class m>
struct Monad
{
    template<typename a>
    static m<a> unit(a value) {
        return m<a>(value);
    }
};

template<typename T>
class Maybe {
    T data_;
    bool is_nothing_;

public:
    // static const Maybe<T> Just(const T val) { return Maybe(val);}
    // static const Maybe<T> Nothing() {return Maybe(); }

    explicit Maybe(T& val): data_{val}, is_nothing_{false} {  }

    explicit Maybe(T&& val): data_{val}, is_nothing_{false} {}
    
    explicit Maybe(): is_nothing_(true) {}


    /*
    Maybe(const Maybe<T>& ma): data_(std::move(ma.data_)), is_nothing_{false} {}

    Maybe(Maybe<T>& ma): data_(std::move(ma.data_)), is_nothing_{false} {}

    Maybe(Maybe<T>&& ma): data_(std::move(ma.data_)), is_nothing_{false} {}

    Maybe<T> operator=(Maybe<T>& ma) {
        return Maybe<T>(std::move(ma));
    }

    Maybe<T> operator=(Maybe<T>&& ma) {
        return Maybe<T>(std::move(ma));
    }
    */
    T data() {
        return data_;
    }

    bool is_nothing() const {
        return is_nothing_;
    }
    
    void show() {
        std::cout << this->to_string() << std::endl;;
    }
    
    std::string to_string() {
        std::ostringstream oss;
        if (!is_nothing_)
            oss << "Maybe::Just " << data_ ;
        else
            oss << "Maybe::Nothing";
        return oss.str();
    }
};

template<typename T>
Maybe<T> Just(T& val)
{
    return Maybe<T>(val);
}

template<typename T>
Maybe<T> Just(T&& val)
{
    return Maybe<T>(val);
}

template<typename T>
Maybe<T> Nothing()
{
    return Maybe<T>();
}

template<> struct Monad<Maybe>
{
    template<typename a>
    static const Maybe<a> unit (a value)
    {
        return Just(value);
    }
};

template<typename T, typename Func>
    auto operator>>=(Maybe<T> ma, Func fun) -> decltype (fun(ma.data()))
{
    decltype(fun(ma.data())) nothing;
    if (ma.is_nothing()) {
        return nothing;
    } else {
        // std::cout << "binding " << ma.data() << std::endl;
        return fun(ma.data());
    }
}


template<typename TA, typename TB>
Maybe<TB> and_then(Maybe<TA> ma, std::function<Maybe<TB>(TA)> &fun)
{
    if(ma.is_nothing()) {        
        return Maybe<TB>();
    } else {        
        return fun(ma.data());
    }            
}
