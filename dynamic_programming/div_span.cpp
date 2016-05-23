#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long mod = 1000000007;


long long power(int x, long long y, long long m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0)? p : (x * p) % m;
} 

long long  modInverse1(int a, long long m)
{
    return power(a, m-2, m);
}


long long modInverse2(long long a, long long mod)
{
	if(mod == 3)
		return a;

	return ((modInverse2((a * a) % mod, mod) * ((mod-2) % 2 == 1 ? a : 1))) % mod; 
}

long long modInverse(long long a, long long index, long long mod)
{
	if(index == 1)
		return a;

	return ((modInverse((a * a) % mod, index / 2, mod) * (index % 2 == 1 ? a : 1))) % mod; 
}

long long biomial(int n, int k)
{
    long long res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        //res /= (i + 1);
        res *= modInverse(i + 1, mod-2, mod);
        res %= mod;
    }
    return res;
}

long long catalan(int n)
{
    long long res = 1;
    res *= biomial(2*n, n);
    //res /= (n + 1);
    res *= modInverse(n + 1, mod-2, mod);
    return res % mod;
}



long long factorial(int n)
{
    long long res = 1;
    while (n) {
        res *= n--;
        res %= mod;
    }
    return res;
}

int main() {


    int T;
    cin >> T;

    //cout << catalan(10) << ", " << modInverse(2, mod-2, mod) << endl;

    for (int t = 0; t < T; ++t) {
        
        int X, Y;
        cin >> X >> Y;
        vector<vector<long>> dp(X+1, vector<long>(Y+1, 0));

        for (int i = 0; i <= X; ++i) dp[i][0] = catalan(i);
        for (int j = 1; j <= Y; ++j) dp[0][j] = catalan(j);

        
        for (int i = 1; i <= X; ++i) {
            for (int j = 1; j <= Y; ++j) {

                long tmp = 0;
                
                for (int i1 = 0; i1 < i; ++i1)
                    for (int j1 = 0; j1 <= j; ++j1) 
                        tmp += dp[i1][j1] * dp[i-1-i1][j-j1] % mod;

                for (int j1 = 0; j1 < j; ++j1) 
                    tmp += dp[0][j1] * dp[i][j-1-j1] % mod;

                dp[i][j] = tmp % mod;
            }
        }
        cout << dp[X][Y] * X * Y % mod << endl;
    }
    
    return 0;
}
