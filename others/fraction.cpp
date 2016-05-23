#include <iostream>
#include <vector>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
        
    if (denominator == 0) return "INF";
    string res = "";
    if (numerator < 0 ^ denominator < 0) res += "-";
        
    long long da = numerator;
    long long db = denominator;

    da = abs(da);
    db = abs(db);
    res += to_string(da / db);
    int mod = da % db; 
    if (mod == 0) return res;
        
    res += ".";
    int pos = res.size();
    vector<int> dig_pos(db, 0);

    while (mod) {
        if(dig_pos[mod]) {
            res.insert(dig_pos[mod], 1, '(');
            res.push_back(')');
            break;
        }
        dig_pos[mod] = pos++;
        mod *= 10;
        res.push_back((mod / db) +'0');
        mod %= db;
    }
    return res;
}



int main(int argc, char ** argv)
{
    cout << fractionToDecimal(-1, 333) << endl;
    return 0;
}
