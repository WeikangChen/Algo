#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


bool Greater(const int& a, const int& b)
{
    stringstream ssa, ssb;
    ssa << a << b;
    ssb << b << a;
    return ssa.str() > ssb.str();
}

class Solution {
public:
    string largestNumber(vector<int> &num) {

    	string res;

    	sort(num.begin(), num.end(), Greater);
        for(auto &a : num) res += to_string(a);

    	if(res[0] == '0') return "0";
    	return res;
    }
};


int main(int argc, char ** argv)
{
    Solution s;
    int as[] = {1125, 232};
    vector<int> vs(as, as + sizeof(as)/sizeof(int));

    cout << s.largestNumber(vs) << endl;
    return 0;
}
