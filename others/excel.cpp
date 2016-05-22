#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        
        string res;
        int m;

        while(n) {
            m = n % 26;
	    m = m == 0 ? 26 : m;
	    res += m - 1 + 'A';
	    n = (n - m) / 26;

        }
	reverse(res.begin(), res.end());

	return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    for(int i = 1; i < 26*27+4; i++)
	cout << s.convertToTitle(i) << " ";
    cout << endl;
    return 0;
}
