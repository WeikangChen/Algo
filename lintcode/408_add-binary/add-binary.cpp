/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-04-13 20:52
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        const int n = a.size();
        const int m = b.size();
        string res;
		int car = 0;
        int i = n-1, j = m-1;
        while(i > -1 || j > -1) 
        {
            int ia = i > -1 ? a[i--]-'0' : 0;
            int ib = j > -1 ? b[j--]-'0' : 0;
			int tm = ia + ib + car;
			res.push_back((tm%2)+'0');
			car = tm / 2;
        }
		if(car)
			res.push_back('1');
		reverse(res.begin(), res.end());

		return res;
    }
};