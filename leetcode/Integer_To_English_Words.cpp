#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string mp1[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",  "Nine", "Ten", "Eleven","Twelve","Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Ninteen"};

string mp10[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};

string how_many(int dig)
{
    if( dig == 0) return "Zero";
    string res = "";
    int i100 = dig / 100;

    if(i100) res += mp1[i100] + " Hundred";
    dig -= 100 * i100;
    int i10 = dig / 10;
    int i1 = dig % 10;
    if(i10 >= 2 )
        res += " " + mp10[i10];
    else
        i1 = dig % 20;
    if(i1) res += " " + mp1[i1];
    return res;
}


int main(int argc, char ** argv)
{
    for(int i = 100; i < 152; i+=3)
    {
        cout << how_many(i) << ", ";
    }

    return 0;
}
