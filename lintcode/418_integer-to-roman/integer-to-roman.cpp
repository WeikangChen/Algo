/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/integer-to-roman
@Language: C++
@Datetime: 16-06-25 15:57
*/

class Solution {
    
    string convert(int n, int m) {
        
        static char one2r[4] = {'I', 'X', 'C', 'M'};
        static char five2r[3] ={'V', 'L', 'D'};
        
        if (n <= 0) return "";
        string res("");
        if (n < 4) {
            res += string(n, one2r[m]);
        } else if (n == 4) {
            res.push_back(one2r[m]);
            res.push_back(five2r[m]);
        } else if (n < 9) {
            res.push_back(five2r[m]);
            res += string(n-5, one2r[m]);
        } else if (n == 9) {
            res.push_back(one2r[m]);
            res.push_back(one2r[m+1]);
        }
        return res;
    }
    
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        
        string res("");
        int unit = 1000;
        for (int i  = 0; i < 4; ++i) {
            res += convert(n/unit, 3-i);
            n %= unit;
            unit /= 10;
        }
        return res;
    }
};