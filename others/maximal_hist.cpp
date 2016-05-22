#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
	const int n = height.size();
	stack<int> stk;
	int res = 0;

	height.push_back(0);
	for(int i = 1; i < n;)
	{
	    if(stk.empty() || height[i] > height[stk.top()]) {
		stk.push(i++);
	    } 
	    else {
		int j = stk.top(); stk.pop();
		int w = stk.empty() ? i : i - stk.top() -1;
		int h = height[j];
		res = max(res, w*h);
	    }
	}
	height.pop_back();
	return res;
    }
};


int main(int argc, char *argv[])
{
    cout << "" << endl;
    return 0;
}
