#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

string add(string s1, string s2)
{
        const int n1 = s1.size();
        const int n2 = s2.size();
        const int n = max(n1, n2);
        string res = "";
        int car = 0;
        for(int i = 0; i < n; ++i)
        {
                int d1 = n1 > i ? s1[n1-1-i]-'0' : 0;
                int d2 = n2 > i ? s2[n2-1-i]-'0' : 0;
                int sum = d1 + d2 + car;
                car = sum / 10;
                sum = sum % 10;
                res.push_back(sum+'0');
        }
        if(car) res += "1";
        reverse(res.begin(), res.end());
        return res;
}

string multiply(string num1, string num2) {
        string res = "0";
        const int n1 = num1.size();
        const int n2 = num2.size();
        for(int i = 0; i < n1; ++i)
                for(int j = 0; j < n2; ++j)
                {
                        int cur = (num1[n1-1-i] - '0') * (num2[n2-1-j] - '0');
                        char dig[4] = "";
                        sprintf(dig, "%d", cur); 
                        string one(dig);
                        for(int z = 0; z < i + j; ++z) one.push_back('0');
                        cout << "res,one =" << res <<  ", " << one << endl;
                        res = add(res, one);
                }

        return res;
}


int main(int argc, char *argv[])
{
        cout << add("12345", "54321") << endl;
        cout << multiply("3", "9") << endl;
        return 0;
}
