#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void get_decimal(int a, int b) {
        string res;
	vector<int> rd(b, 0);
        
	res = to_string(a/b);
	a %= b;
	
        if(!a) {
	    cout << res << endl;
	    return;
	}
	
	string frac;
	int d_position = 1;
	while(a && !rd[a])
	{
            rd[a] = d_position++;
            frac += to_string(10 * a / b);
            a = 10 * a % b;
        }

	if(a) {frac.insert(rd[a]-1, "("); frac += ")";}
	cout << res << "." << frac << endl;
    }
};

int main(int argc, char ** argv)
{
    Solution s;
    s.get_decimal(1, 6);
    s.get_decimal(1, 3);
    s.get_decimal(1, 2);
    s.get_decimal(1, 8);
    s.get_decimal(2, 3);
    s.get_decimal(1, 9);
    s.get_decimal(1, 11);
    s.get_decimal(1, 17);
    s.get_decimal(1, 19);
    s.get_decimal(4, 9);
    s.get_decimal(7, 12);
    s.get_decimal(1, 81);
    s.get_decimal(22, 7);
    s.get_decimal(10, 5);
    s.get_decimal(0, 5);
    return 0;
}
