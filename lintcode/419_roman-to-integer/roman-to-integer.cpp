/*
@Copyright:LintCode
@Author:   chenweikang
@Problem:  http://www.lintcode.com/problem/roman-to-integer
@Language: C++
@Datetime: 16-06-25 18:08
*/

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        static unordered_map<char, int> r2i = {{'I', 1}, {'V', 5}, 
                                            {'X', 10}, {'L', 50},
                                            {'C', 100}, {'D', 500},
                                            {'M', 1000}};
        const int n = s.size();                       
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cur = r2i[s[i]];
            if (i < n-1 && cur < r2i[s[i+1]])
                res -= cur;
            else
                res += cur;
        }
        return res;
    }
};