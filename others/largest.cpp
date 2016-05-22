#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool Greater_String(const string& a, const string& b)
{
    int s = min(a.size(), b.size());
    int i;
    for(i = 0; i < s; ++i)
    {	
	if (a[i] > b[i]) return true;
	if (a[i] < b[i]) return false;
    }

    cout << i << " @ "<< a << endl;
    cout << a[i] << ">"<< a[0] << endl;
    cout << b[i] << ">"<< b[0] << endl;
    if(a.size() > b.size())
        return a[i] > a[0];
    else
        return b[i] < b[0];
}

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
	bool allZero = true;
	
	sort(num.begin(), num.end(), Greater);
	for(int i = 0; i < num.size(); ++i)
	{
	    if(num[i] != 0) allZero = false;
	    stringstream ss;
	    ss << num[i];
	    res += ss.str() + "|";
	}
	if(allZero) return "0";	
	return res;
    }
};

int main(int argc, char ** argv)
{
    int as[] = {123, 12};
    vector<int> arr(as, as+sizeof(as)/4);
    Solution s;
    cout <<  s.largestNumber(arr) << endl;

}
