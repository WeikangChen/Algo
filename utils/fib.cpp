#include <iostream>
#include <vector>

using namespace std;
typedef long int LL;

template<int n>
struct fib_pre {
    static const LL value = fib_pre<n-1>::value + fib_pre<n-2>::value;
};

template<>
struct fib_pre<1> {
    const static LL value = 1;
};


template<>
struct fib_pre<2> {
    const static LL value = 1;
};
    


LL fib_rec(int n) {
    if(n <= 0)
        return 0;
    if(n <= 2)
        return 1;
    return fib_rec(n-1) + fib_rec(n-2);
}

LL fib_it(int n) {
    if(n <= 0)
        return 0;
    if(n <= 2)
        return 1;
    LL fib1 = 1;
    LL fib2 = 1;
    LL fibn = fib1 + fib2;
    for (int i = 2; i < n; i++)
    {
        fibn = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibn; 
    }

    return fibn;
}



int main(int argc, char ** argv)
{
    for(int i = 10; i<= 50; i+=10) {
        cout << "fibonacci(" << i <<  ") = "
            //<< fib_rec(i) << " == "
             << fib_it(i) << endl;
        
    }

    cout << "fib_pre(10)=" << fib_pre<10>::value << endl;
    cout << "fib_pre(20)=" << fib_pre<20>::value << endl;
    cout << "fib_pre(30)=" << fib_pre<30>::value << endl;
    cout << "fib_pre(40)=" << fib_pre<40>::value << endl;

    cout << "fib_pre(10)=" << fib_rec(10) << endl;
    cout << "fib_pre(20)=" << fib_rec(20) << endl;
    cout << "fib_pre(30)=" << fib_rec(30) << endl;
    cout << "fib_pre(40)=" << fib_rec(40) << endl;
    return 0;
}
