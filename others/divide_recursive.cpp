#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        long long int da = (numerator);
        long long int db = (denominator);
        
	da = da > 0 ? da : -da;
	db = db > 0 ? db : -db;
 
        long long s, t;
        s = da / db;
        t = da % db;
        stringstream ss;
        ss << s;
        string integral = ss.str();
        if(t == 0) return integral;
        
        map<int, int> dig;
        int pos = 1;
        string decimal("");
        while(t && !dig[t]) {
            dig[t] = pos++;
            s = 10 * t / db;
            t = 10 * t % db;
            decimal += (s + '0');
        }
        
        if(t) {
            decimal.insert(dig[t]-1, "(");
            decimal += ")";
        }
        
        if( (numerator^denominator) > 0)
            return integral + "." + decimal;
        else
            return "-" + integral + "." + decimal;
        
    }
};


int main(int argc, char ** argv)
{
    Solution s;

    cout << s.fractionToDecimal(1, 3) << endl;
    cout << s.fractionToDecimal(1, 214748364) << endl;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
    cout << s.fractionToDecimal(-2147483648) << endl;
    return 0;
}
