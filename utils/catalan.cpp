#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define COUT(TEST) cout << " ------------------- test " << TEST << " -------------------" << endl

typedef long long ll;

const int MOD = 1000000007;



template<int n>
struct fibonacci_tmpl {
    static const ll value = fibonacci_tmpl<n-1>::value + fibonacci_tmpl<n-2>::value;  
};

template<>
struct fibonacci_tmpl<0>
{
    static const ll value = 1;
};

template<>
struct fibonacci_tmpl<1>
{
    static const ll value = 1;
};




const int NCAT = 10001;
vector<int> catalan_vec(NCAT, 0);
void cal_catalan_ves() {
    catalan_vec[0] = 1;
    for (int i = 1; i < NCAT; ++i) {
	int tmp = 0;
	for (int j = 0; j < i; j++) {
	    tmp += catalan_vec[j] * catalan_vec[i-1-j];
	}
	catalan_vec[i] = tmp;
    }
}


ll power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0)? p : (x * p) % m;
} 

ll  modInverse1(int a, int m)
{
    return power(a, m - 2, m);
}

ll modInverse(int a, int index, int mod)
{
    if(index == 1)
        return a;
    return ((modInverse((a * a) % mod, index / 2, mod) * (index % 2 == 1 ? a : 1))) % mod; 
}

ll binomial(int n, int k)
{
    ll res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll catalan_fun(int n)
{
    return binomial(2 * n, n) / (n + 1);
}

ll factorial(int n)
{
    ll res = 1;
    while (n) 
        res *= n--;
    return res;
}


template<int n>
struct catalan_tmpl {
    static const ll value = (n);
};

template<>
struct catalan_tmpl<0>
{
    static const ll value = 1;
};

template<>
struct catalan_tmpl<1>
{
    static const ll value = 1;
};

int main() {
    COUT("factorial");
    for (int i = 0; i < 10; i += 2)
        cout << "\t factorial("<< i << ") = " << factorial(i) << endl;

    COUT("binomial");
    int N = 4;
    for (int k = 0; k <= N; k++)
        cout << "\t C(" << N << "," << k << ") = " << binomial(N, k) << endl;

    //cal_catalans();
    static ll catalan_arr[] = {catalan_tmpl<0>::value, 
				 catalan_tmpl<1>::value, 
				 catalan_tmpl<2>::value, 
				 catalan_tmpl<3>::value, 
				 catalan_tmpl<4>::value, 
				 catalan_tmpl<5>::value, 
				 catalan_tmpl<6>::value, 
				 catalan_tmpl<7>::value, 
				 catalan_tmpl<8>::value, 
				 catalan_tmpl<9>::value, 
				 catalan_tmpl<10>::value, 
				 catalan_tmpl<11>::value};
    COUT("catalan");
    for (int i = 0; i < 12; i++)
        cout << "\t catalan("<< i << ") = " << catalan_arr[i]
	     << " == " << catalan_fun(i) << endl;
    
    return 0;
}
