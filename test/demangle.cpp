#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>



#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

std::string demangle(const char* name) {

    int status = -4; // some arbitrary value to eliminate the compiler warning

    // enable c++11 by passing the flag -std=c++11 to g++
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status==0) ? res.get() : name ;
}

#else

// does nothing if not g++
std::string demangle(const char* name) {
    return name;
}

#endif

using namespace std;

template<typename T>
string type(const T& t) {
    // return typeid(t).name();
    return demangle(typeid(t).name());
}


struct Base { virtual ~Base() {} };
struct Derived : public Base { };

int main(int argc, char ** argv)
{
    uint32_t x = 256;
    uint32_t *ptr_u32 = &x;
    Base* ptr_base = new Derived(); // Please use smart pointers in YOUR code!
    vector<uint32_t>  vec_u32(10);
    
    cout << "Type of ui32_t: " << type(x) << endl;
    cout << "Type of vec_u32: " << type(ptr_u32) << endl;
    cout << "Type of ptr_base: " << type(ptr_base) << endl;
    cout << "Type of pointee: " << type(*ptr_base) << endl;
    cout << "Type of vector<>: " << type(vec_u32) << endl;

    delete ptr_base;
    
    return 0;
}
 
