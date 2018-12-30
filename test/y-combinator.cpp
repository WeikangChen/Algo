#include <iostream>
#include <vector>
#include <functional>
#include <cstdint>
using namespace std;

using fn_o1_t = function<int32_t(int32_t)>;
using fn_o2_t = function<fn_o1_t(fn_o1_t)>;

/*
fn_o1_t Y(fn_o2_t F) {
    return [&] (int n) { return F(Y(F)) (n); };
}
*/

// using FN_O1 = function<R(T)>;
// using FN_O2 = function<FN_O1(FN_O1)>;
template<typename T, typename R>
function<R(T)> Y1(function<function<R(T)>(function<R(T)>)> F)
{
    // return F(Y1(F)); segment fault due to infinite recursion
    // return [=] (T t) { return F(Y1(F)) (t); };
    return F([=] (T t) { return Y1(F)(t);});
}   

fn_o2_t F0 = [] (fn_o1_t fn1) {
    return [fn1] (int n) { return n == 0 ? 1 : n * fn1(n - 1); };
};

fn_o1_t F1(fn_o1_t fn1) {
    return [fn1] (int n) { return n == 0 ? 1 : n * fn1(n - 1); };
}

int32_t F2(fn_o1_t fn1, int32_t n) {
    return n == 0 ? 1 : n * fn1(n - 1);
};

template<typename F>
struct SF {
    function<F(SF)> fn;
};

template<typename T, typename R>
function<R(T)> Y2(function<function<R(T)>(function<R(T)>)> F)
{
    using fno1_t = function<R(T)>;
    using sfo1_t = SF<fno1_t>;
    sfo1_t sf = {
        [F] (sfo1_t x) {
            return F(fno1_t([x] (T y) { return x.fn(x) (y); })); 
        }
    };

    return sf.fn(sf);
}

template<typename F>
struct self_ref
{
    function<F(self_ref)> fun;
};

template<typename T, typename R>
function<R(T)> Y3(function<function<R(T)>(function<R(T)>)> F)
{
    typedef function<R(T)> f1_t;
    typedef self_ref<f1_t> sr_t;
    sr_t r = {
        [F] (sr_t s) {
            return F([s] (T t) { return s.fun(s) (t); });
        }
    };
    return r.fun(r);
}

int main(int argc, char ** argv)
{
    fn_o1_t fact = [&] (int n) {
        // cout << "fact(n): n = " << n << endl;
        return n == 0 ? 1 : n * fact(n-1);
    };


    cout << " 3! = " << fact(3) << endl;
    // cout << F3(fact)(3) << endl;
    // cout << F1(fact)(3) << endl;
    cout << "Y1(F)(3) = "<< Y1(F0)(5) << endl;
    cout << "Y2(F)(3) = "<< Y2(F0)(5) << endl;
    cout << "Y3(F)(3) = "<< Y3(F0)(5) << endl;
    return 0;
}
